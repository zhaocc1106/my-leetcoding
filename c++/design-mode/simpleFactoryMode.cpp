/**
 * 简单工厂设计模式
 */

#include <iostream>

using namespace std;

typedef enum {
    PROD_A,
    PROD_B
} ProductType;

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

// 工厂类
class Factory {
public:
    Product *create(ProductType type) {
        Product *product = nullptr;
        switch (type) {
            case PROD_A:
                product = new ProductA();
                break;
            case PROD_B:
                product = new ProductB();
                break;
            default:
                break;
        }
        return product;
    }
};

int main() {
    Factory factoryCreator;
    Product *productA = factoryCreator.create(PROD_A);
    Product *productB = factoryCreator.create(PROD_B);

    productA->show();
    productB->show();

    delete productA;
    delete productB;
}