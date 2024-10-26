#include <iostream>
#include <vector>
#include <algorithm>
#include "str.h"

bool sort_fn(MyString* a, MyString* b) {
    return a->lower().c_str()[0] < b->lower().c_str()[0];
}

int main() {
   std::vector<MyString*> strings = {
        new MyString("Banana"),
        new MyString("Apple"),
        new MyString("Cherry"),
        new MyString("Mango"),
        new MyString("Strawberry")
    };

    std::cout << "Start sort" << std::endl;
    for (const auto& str : strings) {
        std::cout << str->c_str() << std::endl;
    }

    std::sort(strings.begin(), strings.end(), sort_fn);

    std::cout << "\nEnd sort" << std::endl;
    for (const auto& str : strings) {
        std::cout << str->c_str() << std::endl;
    }

    for (auto& str : strings)
        delete str;
    return 0;
}