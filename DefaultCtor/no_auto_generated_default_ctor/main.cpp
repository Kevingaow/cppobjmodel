#include <iostream>

class Foo {
    public:
        int mVal;
        Foo *mNext;
};

int main() {

    Foo bar;
    if (bar.mVal || bar.mNext) {
        std::cout << "bar.mVal:" << bar.mVal
            << ", bar.mNext:" << bar.mNext
            << std::endl;
    }

    return 0;
}
