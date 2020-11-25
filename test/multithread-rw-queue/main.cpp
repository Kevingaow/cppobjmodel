#include <queue>
#include <string>
#include <thread>
#include <iostream>

std::queue<std::string> stringQueue{};
std::mutex g_mutex;

void pushElement(){
    for (int i = 0; i < 100000; ++i) {
//        std::lock_guard<std::mutex> lock(g_mutex);
        stringQueue.emplace(std::string("abc"));
    }
}

void popElement(){
    for (int i = 0; i < 100000; ++i) {
//        std::lock_guard<std::mutex> lock(g_mutex);
        if (!stringQueue.empty()){
            stringQueue.pop();
        }
    }
}

int main() {
    std::thread pushTrd(pushElement);
    std::thread popTrd(popElement);

    pushTrd.join();
    std::cout<< "pushTrd exit" << std::endl;
    popTrd.join();
    std::cout<< "popTrd exit" << std::endl;

    return 0;
}
