#ifndef ACID_INCLUDE_FRAMEWORK_TERMINATOR_SYSTEM_H_
#define ACID_INCLUDE_FRAMEWORK_TERMINATOR_SYSTEM_H_


#include <i_system.h>

class TerminatorSystem {
  public:
    TerminatorSystem() = default;
    ~TerminatorSystem() = default;

    void set_terminator(bool* term) {
        terminator = term;
    }

    void terminate() const {
        *terminator = false;
    }

  private:
    bool* terminator = nullptr;
};

#endif  // ACID_INCLUDE_FRAMEWORK_TERMINATOR_SYSTEM_H_
