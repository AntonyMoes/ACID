#ifndef ACID_INCLUDE_SERVER_NETWORK_MANAGER_H_
#define ACID_INCLUDE_SERVER_NETWORK_MANAGER_H_


#include <SFML/Network.hpp>
#include <set>

/*Класс клиента
    Содердит все необходимые данные о соединении с клиентом, а также данные,
    которые пришли от клиента, и данные которые ему нужно отправить
*/

class Client {
  public:
    explicit Client(uint16_t _id);
    //Получает сокет клиента
    sf::TcpSocket& get_socket();
    //Получает пакет для системы по id
    sf::Packet& get_system_packet(uint16_t system_id);
    //Очищает список пакетов для систем
    void clear_system_packets();
    //Возвращает id
    uint16_t get_id();

  private:
    uint16_t id;
    sf::TcpSocket socket;
    std::map<uint16_t, sf::Packet> receive_packet_map;
};

//Интерфейс для обновления информации о подключенных клиентах
class ServerNetworkManager;


class IClientObserver {
  protected:
    //Клиент подключился
    virtual void on_client_connect(uint16_t client_id) = 0;
    //Клиент отключился
    virtual void on_client_disconnect(uint16_t client_id) = 0;
    virtual ~IClientObserver();

  private:
    ServerNetworkManager* manager = nullptr;
    friend class ServerNetworkManager;
};


class ServerNetworkManager {
  public:
    explicit ServerNetworkManager(unsigned short _port);
    //Получает данные из сети
    void process_events();
    //Отправляет даннные, очищает пакеты пришедших данных
    void send();
    //Добавляет данные к отправке
    bool append(uint16_t client_id, sf::Packet& packet, uint16_t system_id);
    void append_all(sf::Packet& packet, uint16_t system_id);
    //Получает дынные по id системы
    sf::Packet& get_received_data(uint16_t client_id, uint16_t system_type);
    //Регистрирует наблбдателя
    void register_observer(IClientObserver* observer);
    //Удаляет наблюдателя
    void unregister_observer(IClientObserver* observer);

  private:
    unsigned short port;
    std::map<uint16_t, Client> clients;
    std::map<uint16_t, sf::Packet> packets_to_send;
    sf::TcpListener listener;
    sf::SocketSelector selector;
    std::set<IClientObserver*> observers;
    void parse_packet(sf::Packet& source, Client& client);
};

#endif  // ACID_INCLUDE_SERVER_NETWORK_MANAGER_H_
