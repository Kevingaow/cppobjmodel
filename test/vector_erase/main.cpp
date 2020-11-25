#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

class test;

std::unordered_map<uint32_t, std::shared_ptr<test>> uom{};

class test {
    public:
        int a;
        std::string b;

        test (int i) {
            a = i;
            std::cout << "test ctor, this:" << this << std::endl;
        }

#if 0
        test (const test& self) {
            std::cout << "test copy, ctor, this:" << this << std::endl;
        }

        const test& operator=(const test&) {
            std::cout << "test operator ctor, this:" << this << std::endl;
        }
#endif

        ~test () {
            std::cout << "~test dtor, this:" << this << std::endl;
        }

    //    test (const test& self) = delete;
     //   const test&operator=(const test&) = delete;

};

void deleteSp(std::shared_ptr<test> obj) {
    std::cout << "in deletesp, ref count:" << obj.use_count() << ", this:" << obj << std::endl;
    std::cout << "out deletesp, ref count:" << obj.use_count() << ", this:" << obj << std::endl;
}

void addSp() {
    std::cout << "in addSp" << std::endl;
    std::shared_ptr<test> t1(new test(32));
    uom[0] = t1;
    std::cout << "out addSp" << std::endl;
}

int main() {
//   std::shared_ptr<test> t1(new test(32));


//    uom.emplace(0, new test('a'));
//    uom.emplace(0, std::make_shared<test> (test('a')));
#if 0
    uom[0] = new test(32);
    std::cout << "before uom.erase 0" << std::endl;
    auto it = uom.find(0);
    std::cout << "after uom find 0, it->a:" << it->second->a << std::endl;
    uom.erase(0);
    std::cout << "after uom.erase 0" << std::endl;
    deleteSp(it->second);
#endif

    addSp();
    std::cout << "after addSp" << std::endl;
    auto it = uom.find(0);
    {
        test* t = nullptr;
        std::shared_ptr<test> tmp = it->second;
        uom.erase(0);
        std::cout << "after uom.erase 0" << std::endl;
        deleteSp(tmp);
    }


    std::cout << "OUT, uom size:"  << uom.size() << std::endl;
}
