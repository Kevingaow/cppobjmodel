#include <stdio.h>
#include <iostream>

using namespace std;

#define MOVE_CTOR
class MovePtr {
public:
    MovePtr() : d(new int(0)) {
        printf("ctor, d:%p\n", d);
    }
#if 1
    MovePtr(const MovePtr& m) : d(new int(*(m.d))) {
        printf("copy ctor\n");
    }
#endif

#ifdef MOVE_CTOR
    MovePtr(MovePtr&& m) : d(m.d) {
        printf("move ctor\n");
        m.d = nullptr;
    }

    MovePtr& operator=(MovePtr&& m) {
        printf("operator move ctor, m.d:%p\n", m.d);
        d = m.d;
        m.d = nullptr;
        return *this;
    }
#endif

    ~MovePtr() {
        printf("dtor, d:%p\n", d);
        delete d;
    }
    int* d;
};

MovePtr getMovePtr() {
//    return move(MovePtr());
    return MovePtr();
}

int main() {
    MovePtr mp = getMovePtr();
    //MovePtr mp2 = mp;
    printf("mp.d:%p\n", mp.d);
    return 0;
}
