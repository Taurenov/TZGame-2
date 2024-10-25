#include <iostream>
#include <vector>
#include <algorithm>
#include "str.h"

bool sort_fn(MyString* a, MyString* b) {
    MyString lower_a = a->lower();
    MyString lower_b = b->lower();
    std::cout << "Comparing: " << lower_a.c_str() << " with " << lower_b.c_str() << std::endl;
    return lower_a.c_str()[0] < lower_b.c_str()[0];
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

    std::cout << "Deleting strings..." << std::endl;
    for (auto& str : strings) {
        std::cout << "Deleting: " << str->c_str() << std::endl;
        delete str;
        str = nullptr;
    }

    std::cout << "All strings deleted successfully." << std::endl;
    return 0;
}