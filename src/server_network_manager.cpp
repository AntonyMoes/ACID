//
// Created by vladimir on 21.11.18.
//
#include <server_network_manager.h>

//TODO: (ukhahev): Add client disconnect

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

void ServerNetworkManager::process_events() {
    if (selector.wait()) {
        if (selector.isReady(listener)) {
            uint16_t id = clients.rbegin()->first;
            Client &client = clients.emplace(id, id).first->second;
            if (listener.accept(client.get_socket()) != sf::Socket::Done) {
                clients.erase(id);
            } else {

            }
        } else {
            for (auto &client : clients) {
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
    return clients[client_id].get_system_packet(system_type);
}

void ServerNetworkManager::append(uint16_t client_id, sf::Packet &packet) {
    auto client_packet = packets_to_send[client_id];
    client_packet << packet;
}

void ServerNetworkManager::send() {
    for (auto &packet : packets_to_send) {
        auto client = clients.find(packet.first);
        if (client != clients.end()) {
            client->second.get_socket().send(packet.second);
        }
    }
}