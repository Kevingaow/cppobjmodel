#include <stdio.h>

class Foo {
    public:
        int mVal;
        Foo *mNext;
};

int main() {

    Foo bar;
    if (bar.mVal || bar.mNext) {
    }
//    printf("addr of mVal:%p, addr of mNext:%p, sizeof(int*):%d\n", &Foo::mVal, &Foo::mNext, sizeof(int*));

    return 0;
}
