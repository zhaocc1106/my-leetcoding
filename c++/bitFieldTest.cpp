/**
 * 位域的理解
 */

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct {
    int a:3;
    int b:5;
    int c:1;
    int d:4;
} type;

int main() {
    // 0100 0010 0110 0000 0000 0000 0000 0000
    type type1;
    type1.a = 2;
    type1.b = 8;
    type1.d = 3;
    uint8_t bytes[4];
    cout << sizeof(type1) << endl;
    memcpy(bytes, &type1, sizeof(type1));
    for (uint8_t byte : bytes) {
        printf("0x%x\n", byte);
    }
}
