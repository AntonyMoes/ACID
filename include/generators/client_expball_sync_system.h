#ifndef ACID_INCLUDE_CLIENT_EXPBALL_SYNC_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_EXPBALL_SYNC_SYSTEM_H_


#include <active_system.h>
#include <network_id.h>
#include <network_manager.h>
#include <entity_life_system.h>
#include <exp_ball.h>


class ClientExpBallSyncSystem: public ActiveSystem<NoneNode>, public EntityLifeSystem {
  public:
    explicit ClientExpBallSyncSystem(NetworkManager* net): net(net) {}

    void execute() {
        auto packet = net->get_system_packet(EXPBALL_CREATE_SYSTEM);
        while (!packet.endOfPacket()) {
            uint16_t id = 0;
            float x = 0;
            float y = 0;
            uint16_t exp = 0;
            packet >> id >> x >> y >> exp;
            b2Vec2 pos{x, y};
            auto ball = new ExpBall(pos, exp);
            ball->set_id(id);
            create_entity(ball);
        }
    }

  private:
    NetworkManager* net;
};

#endif  // ACID_INCLUDE_CLIENT_EXPBALL_SYNC_SYSTEM_H_
