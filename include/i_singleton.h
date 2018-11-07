#ifndef ACID_INCLUDE_I_SINGLETON_H_
#define ACID_INCLUDE_I_SINGLETON_H_


class ISingleton {
  public:
    static ISingleton& get_instance();

    ISingleton(ISingleton const&) = delete;
    ISingleton& operator= (ISingleton const&) = delete;

  protected:
    ISingleton() = default;
    virtual ~ISingleton();

};

#endif  // ACID_INCLUDE_I_SINGLETON_H_
