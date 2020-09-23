/**
 * 策略模式
 *
 * 策略模式定义了一系列的算法，并将每一个算法封装起来，而且使它们还可以相互替换。策略模式让算法独立于使用它的客户而独立变化。
 */

#include <iostream>

using namespace std;

class AlgorBase {
public:
    virtual void alg() = 0;

    virtual ~AlgorBase() {
        cout << "AlgorBase destruction" << endl;
    }
};

class AlgorA : public AlgorBase {
public:
    void alg() {
        cout << "AlgorA algorithm" << endl;
    }

    ~AlgorA() {
        cout << "AlgorA destruction" << endl;
    }
};

class AlgorB : public AlgorBase {
public:
    void alg() {
        cout << "AlgorB algorithm" << endl;
    }

    ~AlgorB() {
        cout << "AlgorB destruction" << endl;
    }
};

class Context {
private:
    AlgorBase *alg;
public:
    Context(AlgorBase *alg) : alg(alg) {};

    ~Context() {
        cout << "Context destruction" << endl;
        if (alg != nullptr) {
            delete alg;
        }
    };

    void algFunc() {
        if (alg != nullptr) {
            alg->alg();
        }
    }
};

int main() {
    Context ctx(new AlgorA);
    Context ctx2(new AlgorB);
    ctx.algFunc();
    ctx2.algFunc();
}