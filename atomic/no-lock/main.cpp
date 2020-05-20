#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std::chrono;

const unsigned int Int32Max = 0x000FFFFF;
volatile unsigned int count = 0;

void  singleThreadUpdate() {
    for (; count < Int32Max; ++count);
}


std::mutex data_mutex;
std::condition_variable data_var;
bool flag = true;

void multiThreadUpdateWithLockA() {
//    std::cout << "multiThreadUpdateA, thd id:"
//                << std::this_thread::get_id() << std::endl;
    while(count < Int32Max) {
        std::unique_lock<std::mutex> lck(data_mutex) ;
        ++count;
 //       std::cout << "AAA" << std::endl;
        data_var.wait(lck,[]{return flag;});
        flag = false;
        data_var.notify_one();
    }
}

void multiThreadUpdateWithLockB () {
//    std::cout << "multiThreadUpdateB, thd id:"
//                << std::this_thread::get_id() << std::endl;
    while (count < Int32Max) {
        std::unique_lock<std::mutex> lck(data_mutex) ;
        ++count;
//        std::cout << "BBB" << std::endl;
        data_var.wait(lck,[]{return !flag;});
        flag = true;
        data_var.notify_one();
    }
}

void multiThreadUpdateWithLock() {
    std::thread ta(multiThreadUpdateWithLockA);
    std::thread tb(multiThreadUpdateWithLockB);
    ta.join();
    tb.join();
}


std::atomic<bool> mAtomicFlag(false);

void multiThreadUpdateAtomicA() {
    while (count < Int32Max) {
        while(mAtomicFlag.load());

        ++count;
//        std::cout << "atomicAAA,count" << count << std::endl;
        mAtomicFlag.store(true);
    }
}

void multiThreadUpdateAtomicB() {
    while (count < Int32Max) {
        while(!mAtomicFlag.load());

        ++count;
//        std::cout << "atomicBBB,count" << count << std::endl;
        mAtomicFlag.store(false);
    }
}

void multiThreadUpdateAtomic() {
    std::thread ta(multiThreadUpdateAtomicA);
    std::thread tb(multiThreadUpdateAtomicB);
    ta.join();
    tb.join();
}

int main() {
    auto start = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    singleThreadUpdate();
    auto end = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    std::cout << "singleTHreadUpdate cost:" << (end.count() - start.count()) << "ms"<< std::endl;

    count = 0;
    start = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    multiThreadUpdateAtomic();
    end = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    std::cout << "multiThreadUpdateAtomic cost:" << (end.count() - start.count()) << "ms"<< std::endl;

    count = 0;
    start = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    multiThreadUpdateWithLock();
    end = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    std::cout << "multiThreadUpdateWithLock cost:" << (end.count() - start.count()) << "ms"<< std::endl;


    return 0;
}
