#include <iostream>

const char* p = "a";
char* const q = "t";

using namespace std;

class Obj {
    public:
    Obj() = default;
    Obj(int _x, int _y) : x(_x), y(_y){
    }

    const Obj& operator= (const Obj&) const {
        return *this;
    }

    int getX() {
        cout << "getX()" << endl;
        return x;
    }

    int getX() const {
        cout << "getX() const" << endl;
        return x;
    }

    private:
    int x;
    int y;
};

class ConstTest {
    public:
        ConstTest() = default;
        void foo(const int* i){ 
            int a = 100;
            i = &a;
            //*i = a;  // ERROR!
            value1 = *i;
        }

        void bar(const Obj& o) {
            cout << o.getX() << endl;
        }

        void bar(Obj& o) const {
            cout << o.getX() << endl;
        }

    private:
        int value1;
        int value2;
};

int main() {
    ConstTest ct;
    int a = 10;
    ct.foo(&a);

    char tmp('b');
    p = &tmp;
//    *p = 'c'; // ERROR, const data

    char arr[] = "aaa";
//    cout << "*q:" << *q << ", q:" << hex << &q
//        << ", arr[0]:" << arr[0] << ", arr:" << hex << &arr << endl;
//    *q = arr[0];
//    q = &tmp; // ERROR, const pointer


    Obj o(100, 200);
    ct.bar(o);

    const ConstTest ct2;
    ct2.bar(o);
    return 0;

}
