/**
 * c++自带正则表达式功能
 */

#include <iostream>
#include <regex>

using namespace std;

int main() {
    string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    // 在 C++ 中 `\` 会被作为字符串内的转义符，为使 `\.` 作为正则表达式传递进去生效，需要对 `\` 进行二次转义，从而有 `\\.`
    regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname: fnames)
        cout << fname << ": " << regex_match(fname, txt_regex) << endl;

    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;
    for(const auto &fname: fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // sub_match 的第一个元素匹配整个字符串
            // sub_match 的第二个元素匹配了第一个括号表达式
            if (base_match.size() == 2) {
                std::string base = base_match[1].str();
                std::cout << "sub-match[0]: " << base_match[0].str() << std::endl;
                std::cout << fname << " sub-match[1]: " << base << std::endl;
            }
        }
    }
}
