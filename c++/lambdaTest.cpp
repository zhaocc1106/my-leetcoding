/**
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    for_each(arr.begin(), arr.end(), [](int i) {
        cout << i << endl;
    });

    int total = 0;
    for_each(begin(arr), end(arr), [&total](int x) mutable
    {
        total += x;
    });
    cout << total << endl;
}
