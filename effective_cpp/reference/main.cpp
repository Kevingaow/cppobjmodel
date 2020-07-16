#include <stdio.h>

class Ref {
public:
    Ref* mP1;
    Ref* mP2;
    int mInt;
    int& mRef1;
    int& mRef2;
    Ref() : mP1(nullptr), mP2(nullptr), mInt(5), mRef1(mInt), mRef2(mInt) {


    }

};


//void passByRef(Ref& r) {
//
//    std::cout << " by ref:" << std::hex << &r << std::endl;
//}
//
//void passByValue(Ref r) {
//
//    std::cout << " by value:" << std::hex << &r << ", sizeof(r):" << sizeof(r) << std::endl;
//}
//
//void passByPointer(Ref* r) {
//
//    std::cout << " by pointer:" << std::hex << &r << ", sizeof(r):" << sizeof(r) << std::endl;
//}

int main() {
    Ref r;

    printf("sizeof(r~~):%lu\n", sizeof(r.mP1));
//    std::cout << "sizeof(r):" << sizeof(r) << std::endl;
//    std::cout << std::hex << &r << std::endl;

//    passByRef(r);
//    passByValue(r);
//    passByPointer(&r);

    return 0;
}
