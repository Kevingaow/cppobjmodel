#include <stdio.h>
#include <iostream>

using namespace std;

class Base final {
public:
    Base() = default;
    Base(const Base&) = delete;
    Base& operator= (const Base&) = delete;
};


class Derive {
public:
    Derive() = default;
};

int main() {
    Base b1;

    Derive d1;
//    Derive d2 = d1;
//    Derive d3(d1);

    return 0;
}
