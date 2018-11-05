#ifndef ACID_INCLUDE_I_SYSTEM_H_
#define ACID_INCLUDE_I_SYSTEM_H_

template <class T>
class ISystem {
  public:
    virtual void execute() = 0;
};

#endif  // ACID_INCLUDE_I_SYSTEM_H_
