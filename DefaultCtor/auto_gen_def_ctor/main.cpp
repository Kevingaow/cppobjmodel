#include <stdio.h>

class Foo {
    public:
        Foo();
        void test();
};

Foo::Foo() {}

void Foo::test() {}

class Bar {
public:
    Foo mFoo;
    char *mStr;
};

int main() {
    Bar b;

    if (b.mStr) {
    }

    printf("addr of Foo::test():%p\n", &Foo::test);
    printf("addr of Foo::mFoo():%p\n", &Bar::mFoo);
    printf("addr of Foo::mStr():%p\n", &Bar::mStr);

    return 0;
}
