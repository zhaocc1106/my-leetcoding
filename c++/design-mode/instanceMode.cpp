/**
 * 单例模式的实现
 */

#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

// lazy-initialized 懒汉模式,线程不安全，内存泄漏（只有new，没有delete）
class Singleton1 {
private:
    /* 构造函数、拷贝构造函数、赋值构造函数全部隐藏 */

    Singleton1() {
        cout << "construction" << endl;
    }

    Singleton1(const Singleton1 &) = delete;

    Singleton1 &operator=(const Singleton1 &) = delete;

    static Singleton1 *instance;

public:
    ~Singleton1() {
        cout << "destruction" << endl;
    }

    static Singleton1 *getInstance() {
        return new Singleton1;
    }
};

Singleton1 *Singleton1::instance = nullptr;

// lazy-initialized 懒汉模式，通过加锁，使用智能指针可以防止出现内存泄漏和线程不安全，开销较大
class Singleton2 {
private:
    /* 构造函数、拷贝构造函数、赋值构造函数全部隐藏 */

    Singleton2() {
        cout << "construction" << endl;
    }

    Singleton2(const Singleton2 &) = delete;

    Singleton2 &operator=(const Singleton2 &) = delete;

    static shared_ptr<Singleton2> instance;
    static mutex instLock;

public:
    ~Singleton2() {
        cout << "destruction" << endl;
    }

    static shared_ptr<Singleton2> getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lk(instLock); // RAII语法加锁，析构时自动解锁
            if (instance == nullptr) {
                instance = shared_ptr<Singleton2>(new Singleton2);
            }
        }
        return instance;
    }
};

shared_ptr<Singleton2> Singleton2::instance = nullptr;
mutex Singleton2::instLock;

// 最推荐的懒汉单例（magic static）--局部静态变量
class Singleton3 {
private:
    Singleton3() {
        cout << "construction func" << endl;
    }

    Singleton3(const Singleton3 &) = delete;

    Singleton3 &operator=(const Singleton3 &) = delete;

public:
    ~Singleton3() {
        cout << "destruction func" << endl;
    }

    static Singleton3 &getInstance() {
        static Singleton3 instance;
        return instance;
    }
};

// CRTP 奇异递归模板模式实现
template<class T>
class Singleton {
public:
    static T &getInstance() {
        static T instance;
        return instance;
    }

    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

    virtual ~Singleton() {
        cout << "destruction func" << endl;
    }

protected:
    // 方便派生类继承构造函数
    Singleton() {
        cout << "construction func" << endl;
    }
};

class Derived : public Singleton<Derived> {
    friend class Singleton<Derived>; // 设置单例模板类为友元类，这样就能访问衍生类的私有构造函数
public:
    Derived(const Derived &) = delete;

    Derived &operator=(const Derived &) = delete;

private:
    Derived() = default; // 使用父类的构造函数
};

int main() {
    // shared_ptr<Singleton2> ptr1 = Singleton2::getInstance();
    // shared_ptr<Singleton2> ptr2 = Singleton2::getInstance();
    // Singleton3 &singleton3 = Singleton3::getInstance();
    Derived &derived = Singleton<Derived>::getInstance();
    Derived &derived2 = Singleton<Derived>::getInstance();
}