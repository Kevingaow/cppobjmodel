#include <iostream>


class Data{
  public:
    int a;
    static int b;
    int c;
    static int d;
    int e;
    float x, y, z;
    virtual void foo() {}
};

int Data::b;
int Data::d;

int main() {

    printf("sizeof(int):%d, sizeof(float):%d\n", sizeof(int), sizeof(float));
    printf("addr of a:%p\n", &Data::a);
    printf("addr of b:%p\n", &Data::b);
    printf("addr of c:%p\n", &Data::c);
    printf("addr of d:%p\n", &Data::d);
    printf("addr of e:%p\n", &Data::e);
    printf("addr of x:%p\n", &Data::x);
    printf("addr of y:%p\n", &Data::y);
    printf("addr of z:%p\n", &Data::z);

    Data d;

    Data::b;

    d.b;

    int Data::*c = &Data::c;
    printf("addr of Data::*c:0x%x\n", c);

    return 0;
}
