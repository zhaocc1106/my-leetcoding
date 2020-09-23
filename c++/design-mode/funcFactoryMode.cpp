/**
 * 工厂方法模式
 * 相比较简单工厂模式，这种模式方便产品类型的扩展
 */

#include <iostream>

using namespace std;

// 产品基类
class Product {
public:
    virtual void show() = 0;

    virtual ~Product() {
        cout << "Product destruction." << endl;
    }
};

// 产品具体类
class ProductA : public Product {
public:
    void show() {
        cout << "ProductA show" << endl;
    }
};

class ProductB : public Product {
public:
    void show() {
        cout << "ProductB show" << endl;
    }
};

class Factory {
public:
    virtual Product *create() = 0;
};

class FactoryA : public Factory {
public:
    Product *create() {
        return new ProductA();
    }
};

class FactoryB : public Factory {
public:
    Product *create() {
        return new ProductB();
    }
};

int main() {
    Product *productA = FactoryA().create();
    Product *productB = FactoryB().create();

    productA->show();
    productB->show();

    delete productA;
    delete productB;
}