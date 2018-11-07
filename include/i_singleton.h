#ifndef ACID_INCLUDE_I_SINGLETON_H_
#define ACID_INCLUDE_I_SINGLETON_H_

template<class T>
class ISingleton {
  public:
    static T& get_instance();

    ISingleton(ISingleton<T> const&) = delete;
    ISingleton<T>& operator= (ISingleton<T> const&) = delete;

  protected:
    ISingleton() = default;
    virtual ~ISingleton();

};

#endif  // ACID_INCLUDE_I_SINGLETON_H_
