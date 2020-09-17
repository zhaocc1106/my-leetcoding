/**
 * 智能指针测试
 */

#include <iostream>
#include <memory>

using namespace std;

class Node {
public:
    weak_ptr<Node> next; // 使用弱指针，防止出现循环依赖问题

    Node() {
        cout << "construction." << endl;
    }

    ~Node() {
        cout << "destruction." << endl;
    }

    void func() {
        cout << "func" << endl;
    }
};

int main() {
    weak_ptr<Node> weakPtr;
    {
        shared_ptr<Node> p1(new Node);
        shared_ptr<Node> p2(new Node);
        p1->next = p2;
        p2->next = p1;
        cout << p1.use_count() << endl; // 输出为1，因为next是弱指针
        cout << p2.use_count() << endl;
        p1->func();
        p1->next.lock()->func(); // 弱指针如果想访问对象，必须使用lock转成强指针
        shared_ptr<Node> p3 = p1->next.lock();
        cout << p3.use_count() << endl;
        weakPtr = p3;
    }
    cout << weakPtr.use_count() << endl; // 对象已经释放，输出为0
    cout << weakPtr.expired() << endl; // 对象已释放，已过期
}