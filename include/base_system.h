#ifndef ACID_INCLUDE_BASE_SYSTEM_H_
#define ACID_INCLUDE_BASE_SYSTEM_H_


class BaseSystem {
  public:
    virtual ~BaseSystem() = default;
    virtual void execute() const = 0;
    virtual void run() = 0;
};

#endif  // ACID_INCLUDE_BASE_SYSTEM_H_
