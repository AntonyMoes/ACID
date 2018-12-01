//
// Created by vladimir on 21.11.18.
//
#include <server_network_manager.h>
#include <stdexcept>
#include <iostream>
#include <SFML/System.hpp>
//TODO: (ukhahev): Fix client disconnect

Client::Client(uint16_t _id): id(_id) {
    socket.setBlocking(false);
}

sf::TcpSocket& Client::get_socket() {
    return socket;
}

uint16_t Client::get_id() {
    return id;
}

sf::Packet& Client::get_system_packet(uint16_t system_id) {
    return receive_packet_map[system_id];
}

ServerNetworkManager::ServerNetworkManager(unsigned short _port): port(_port) {
    listener.listen(_port);
    selector.add(listener);
}

void Client::clear_system_packets() {
    receive_packet_map.clear();
}


IClientObserver::~IClientObserver() {
    if (manager != nullptr) {
        manager->unregister_observer(this);
    }
}

void ServerNetworkManager::process_events() {
    if (selector.wait(sf::milliseconds(1))) {

        if (selector.isReady(listener)) {
            std::cout << "connected" << std::endl;
            uint16_t id = 1;
            if (clients.rbegin() != clients.rend()) {
                id = clients.rbegin()->first + uint16_t(1);
            }
            Client &client = clients.emplace(id, id).first->second;
            if (listener.accept(client.get_socket()) != sf::Socket::Done) {
                clients.erase(id);
            } else {
                for (auto observer : observers) {
                    observer->on_client_connect(id);
                }
            }
        } else {
            for (auto &client : clients) {
                std::cout << "some packet" << std::endl;
                sf::TcpSocket& socket = client.second.get_socket();
                if (selector.isReady(socket)) {
                    sf::Packet receive_packet;
                    socket.receive(receive_packet);
                    parse_packet(receive_packet, client.second);
                }
            }
        }
    }
}

void ServerNetworkManager::register_observer(IClientObserver *observer) {
    observer->manager = this;
    observers.insert(observer);
}

void ServerNetworkManager::unregister_observer(IClientObserver *observer) {
    auto it = observers.find(observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}
void ServerNetworkManager::parse_packet(sf::Packet &receive_packet, Client &client) {
    while (!receive_packet.endOfPacket()) {
        uint16_t id = 0;
        uint16_t size = 0;
        receive_packet >> id >> size;

        sf::Packet& system_packet = client.get_system_packet(id);

        for (size_t j = 0; j < size; ++j) {
            sf::Int8 byte = 0;
            receive_packet >> byte;
            system_packet << byte;
        }
    }
}

sf::Packet& ServerNetworkManager::get_received_data(uint16_t client_id, uint16_t system_type) {
    auto iter = clients.find(client_id);
    if (iter != clients.end()) {
        return iter->second.get_system_packet(system_type);
    }
    throw std::out_of_range("Client doesn't exists!");
}

bool ServerNetworkManager::append(uint16_t client_id, sf::Packet &packet, uint16_t system_id) {
    if (clients.find(client_id) != clients.end()) {
        auto client_packet = packets_to_send[client_id];
        client_packet << system_id << uint16_t(packet.getDataSize()) << packet;
        return  true;
    }
    return false;
}

void ServerNetworkManager::send() {
    for (auto packet = packets_to_send.begin(); packet !=  packets_to_send.end(); ++packet) {

        auto client = clients.find(packet->first);
        if (client != clients.end()) {
            sf::TcpSocket& socket = client->second.get_socket();
            //if (!socket.Disconnected) {
            // TODO DELETE!!!
            packet->second << uint16_t(1) << uint16_t(8) << int(2) << int(-1);
            if (!packet->second.endOfPacket()) {
                socket.send(packet->second);
            }

            //} else {
              //  for (auto observer : observers) {
               //     observer->on_client_disconnect(client->first);
             //   }
             //   clients.erase(packet->first);
            //    packet = packets_to_send.erase(packet);
            //}
            packet->second.clear();
            client->second.clear_system_packets();
        }
    }
}

