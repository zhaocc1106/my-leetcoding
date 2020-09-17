/**
 * 异常抛出和捕获
 */

#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
public:
    const char * what() const throw() {
        return "My exception";
    }
};

int main() {
    try {
        throw runtime_error("123");
    } catch (MyException &e) {
        cout << e.what() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << "end" << endl;
}