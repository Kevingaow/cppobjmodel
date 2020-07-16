#include <iostream>

using namespace std;

class Base {
    private:
        int x;

    public:
        virtual void mf1() = 0;
        virtual void mf1(int);
        virtual void mf2();
        void mf3();
        void mf3(double);
};

void Base::mf1(int) {
    cout << "Base::mf1(int)" << endl;
}

void Base::mf2() {
    cout << "Base::mf2()" << endl;
}

void Base::mf3() {
    cout << "Base::mf3()" << endl;
}

void Base::mf3(double) {
    cout << "Base::mf3(double)" << endl;
}

//--------------------------------------
class Derived : private Base {
    public:
//        using Base::mf1;
//        using Base::mf3;

        virtual void mf1();
        void mf3();
        void mf4();
};

void Derived::mf1() {
    Base::mf1(22);
    cout << "Derived::mf1()" << endl;
}

void Derived::mf3() {
    cout << "Derived::mf3()" << endl;
}

void Derived::mf4() {
    cout << "Derived::mf4()" << endl;
}

int main() {

    Derived d;
    d.mf1();
    d.mf3();
    d.mf4();


    return 0;
}
