#ifndef ACID_INCLUDE_NETWORK_MANAGER_H_
#define ACID_INCLUDE_NETWORK_MANAGER_H_

#include <SFML/Network.hpp>
#include <queue>
#include <iterator>
#include <mutex>

using package_iterator = std::map<uint16_t, sf::Packet*>::iterator;

class NetworkManager {
  public:
    NetworkManager();
    bool connect(std::string ip, unsigned short port);
    void append(sf::Packet& packet, uint16_t system_id);
    void send();
    void receive();
    sf::Packet& get_system_packet(uint16_t system_type);

  private:
    std::map<uint16_t, sf::Packet> packet_map;
    sf::TcpSocket socket;
    sf::Packet packet;
    sf::SocketSelector selector;
};
#endif  // ACID_INCLUDE_NETWORK_MANAGER_H_
