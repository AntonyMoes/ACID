
#ifndef A_C_I_D_SERVER_NETWORK_MANAGER_H
#define A_C_I_D_SERVER_NETWORK_MANAGER_H

#include <SFML/Network.hpp>

class Client {
  public:
    explicit Client(uint16_t _id);

    sf::TcpSocket& get_socket();
    sf::Packet& get_system_packet(uint16_t system_id);
    uint16_t get_id();
  private:
    uint16_t id;
    sf::TcpSocket socket;
    std::map<uint16_t, sf::Packet> receive_packet_map;
};


class ServerNetworkManager {
  public:
    explicit ServerNetworkManager(unsigned short _port);
    void process_events();
    void send();
    void append(uint16_t client_id, sf::Packet& packet);
    sf::Packet& get_received_data(uint16_t client_id, uint16_t system_type);

  private:
    unsigned short port;
    std::map<uint16_t, Client> clients;
    std::map<uint16_t, sf::Packet> packets_to_send;
    sf::TcpListener listener;
    sf::SocketSelector selector;

    void parse_packet(sf::Packet& source, Client& client);
};


#endif //A_C_I_D_SERVER_NETWORK_MANAGER_H
