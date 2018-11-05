#ifndef ACID_INCLUDE_I_SINGLETON_H_
#define ACID_INCLUDE_I_SINGLETON_H_


class ISingleton {
  public:
    static ISingleton* get_instance();
    virtual ~ISingleton();

  protected:
    ISingleton();

  private:
    static ISingleton* instance;
};

#endif  // ACID_INCLUDE_I_SINGLETON_H_
