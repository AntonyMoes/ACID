//
// Created by antonymo on 13.11.18.
//

#ifndef ACID_INCLUDE_FRAMEWORK_TERMINATOR_SYSTEM_H_
#define ACID_INCLUDE_FRAMEWORK_TERMINATOR_SYSTEM_H_


#include <i_system.h>
#include <game_loop.h>

template <class T>
class TerminatorSystem : public ISystem<T> {
  public:
    TerminatorSystem() = default;
    ~TerminatorSystem() = default;

    void set_loop(GameLoop* l) {
        loop = l;
    }

    void terminate() {
        loop->terminate();
    }

  private:
    GameLoop* loop = nullptr;
};

#endif  // ACID_INCLUDE_FRAMEWORK_TERMINATOR_SYSTEM_H_
