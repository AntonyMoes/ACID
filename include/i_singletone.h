#ifndef ACID_INCLUDE_I_SINGLETONE_H_
#define ACID_INCLUDE_I_SINGLETONE_H_


class ISingletone {
  public:
    static ISingletone* get_instance();
    virtual ~ISingletone();

  protected:
    ISingletone();

  private:
    static ISingletone instance;
};

#endif  // ACID_INCLUDE_I_SINGLETONE_H_
