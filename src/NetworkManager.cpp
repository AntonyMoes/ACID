#include <network_manager.h>
#include <network_id.h>

NetworkManager::NetworkManager() : packet(new sf::Packet) {

}

void NetworkManager::send() {

    packet_mutex.lock();
        packet = new sf::Packet();
        sf::Packet* send_packet = packet;
    packet_mutex.unlock();

    socket.send(*send_packet);
    delete send_packet;
}

void NetworkManager::receive() {
    sf::Packet receive_packet;
    socket.receive(receive_packet);

    while (!receive_packet.endOfPacket()) {
        uint16_t id = 0;
        receive_packet >> id;
        sf::Packet* system_packet = nullptr;
        auto iter = packet_map.find(id);

        if (iter == packet_map.end()) {
            system_packet = new sf::Packet();
        } else {
            system_packet = iter->second;
        }
        packet_map.emplace(id, system_packet);
        uint16_t size = 0;
        receive_packet >> size;

        for (size_t j = 0; j < size; ++j) {
            uint8_t byte = 0;
            receive_packet >> byte;
        }
    }
}

void NetworkManager::append(sf::Packet& a_packet) {
    packet_mutex.lock();
        *packet << uint16_t(a_packet.getDataSize()) << a_packet;
    packet_mutex.unlock();
}

bool NetworkManager::connect(std::string ip, unsigned short port, std::string nick_name) {
    socket.connect(ip, port);
    sf::Packet hello_packet;
    hello_packet << uint16_t(NICKNAME_PACKET_ID) << name;
    socket.send(hello_packet);
}

package_iterator NetworkManager::packets_begin(uint16_t system_type) {
    return packet_map.find(system_type);
}

package_iterator NetworkManager::packets_end(uint16_t system_type) {
    auto end = packet_map.find(system_type);
    while (end != packet_map.end() && end->first == system_type) {
        end++;
    }
    return end;
}