#pragma once

#include <memory>
template <typename T> class Singleton
{
  protected:
    std::shared_ptr<T> object;
    static Singleton *singleton;

    Singleton() = default;

  public:
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton &operator=(Singleton &&) = delete;

    static Singleton *getInstance()
    {
        if (!singleton)
            singleton = new Singleton<T>();

        return singleton;
    }

    void setObject(std::shared_ptr<T> object)
    {
        this->object = object;
    }
    std::shared_ptr<T> getObject() const
    {
        return object;
    }

    static void destroyInstance()
    {
        delete singleton;
        singleton = nullptr;
    }
};

template <typename T> Singleton<T> *Singleton<T>::singleton = nullptr;
