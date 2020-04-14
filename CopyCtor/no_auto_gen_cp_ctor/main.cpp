#include <iostream>
#include "stdio.h"

class Foo {
    public:
        Foo(const char* c) {
            printf("ctor, this:%p\n", this);
            str = c;
        }

        ~Foo(){
            printf("enter dtor this:%p, str:%s, %p\n", this, str, str);
            delete [] str;
            printf("leave dtor str:%s, %p\n", str, str);
        }

        const char* getStr() const {
            return str;
        }

    private:
        int mVal;
        const char* str;
//        std::string mstring;
};


void test(Foo foo) {
    printf("[test] enter\n");
    Foo myFoo = foo;
//    printf("[test] leave, myFoo.getStr():%s\n", myFoo.getStr());
   printf("&foo:%p, &myFoo:%p\n", &foo, &myFoo);
    printf("[test] leave\n");
}

int main() {
    const char* c = new char[5];

    Foo bar(c);
    printf("addr of bar:%p\n", &bar);
    test(bar);
    printf("[main] after test\n");

    delete [] c;
//    printf("leave main:: bar.getStr():%s, %p\n", bar.getStr(), bar.getStr());
    return 0;
}
