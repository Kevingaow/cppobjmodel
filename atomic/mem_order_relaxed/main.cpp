#include <atomic>
#include <thread>
#include <assert.h>
#include <iostream>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y() {
    x.store(true, std::memory_order_relaxed);
    y.store(true, std::memory_order_relaxed);
}

void read_y_then_x() {
    while(!y.load(std::memory_order_relaxed));
    if(x.load(std::memory_order_relaxed))
        ++z;
}


void loop() {
    int i = 0;
    while(i < 0x000FFFFF) {
        x = false;
        y = false;
        z = 0;
        std::thread a(write_x_then_y);
        std::thread b(read_y_then_x);

        a.join();
        b.join();

//        if (i % 1000000 == 0) {
//            std::cout << "z.load():" << z.load() << ", i:" << i << std::endl;
//        }
        assert(z.load() != 0);
        ++i;
    }
    std::cout << "exit loop, i:" << std::hex << i << std::endl;
}

int main() {
    loop();
    return 0;
}
