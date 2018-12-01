#include <network_manager.h>
#include <network_id.h>
#include <iostream>
NetworkManager::NetworkManager() {
    socket.setBlocking(false);
}

void NetworkManager::send() {
    socket.send(packet);
    packet.clear();
}

void NetworkManager::receive() {
    sf::Packet receive_packet;


    socket.receive(receive_packet);

    while (!receive_packet.endOfPacket()) {
        uint16_t id = 0;
        uint16_t size = 0;
        receive_packet >> id >> size;
        std::cout << id << std::endl;
        sf::Packet& system_packet = packet_map[id];

        for (size_t j = 0; j < size; ++j) {
            sf::Int8 byte = 0;
            receive_packet >> byte;
            system_packet << byte;
        }
    }
}

void NetworkManager::append(sf::Packet& a_packet, uint16_t system_id) {
    packet << system_id << uint16_t(a_packet.getDataSize()) << a_packet;
}

bool NetworkManager::connect(std::string ip, unsigned short port) {
    auto status = socket.connect(ip, port);
    if (status == sf::Socket::Status::Done) {
        return true;
    }
    return false;
}

sf::Packet& NetworkManager::get_system_packet(uint16_t system_type) {
    return packet_map[system_type];
}