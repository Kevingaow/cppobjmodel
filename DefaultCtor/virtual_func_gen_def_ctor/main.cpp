#include <iostream>

class Point {

    public:
        virtual void print() = 0;

        int A;
};

class Point2d : public Point {
    public:
        virtual void print();
        int B;
        void test();
};

void Point2d::print() {
//    std::cout<< "Point2d::print" << std::endl;
}

void Point2d::test() {
}

int main() {

    Point2d p2d;
    Point& p = p2d;
    p.print();

    printf("addrs of print:%p\n", &Point::print);
    printf("addrs of print:%p\n", &Point2d::print);
    printf("addrs of test:%p\n", &Point2d::test);
    printf("addrs of A:%p\n", &Point::A);
    printf("addrs of B:%p\n", &Point2d::B);
    return 0;
}
