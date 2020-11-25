#include <deque>
#include <iostream>

class Content {
    public:
        Content(int count) : mCount(count) {
            std::cout << "Content ctor, mCount->" << mCount << std::endl;
        }

        virtual ~Content() {
            std::cout << "Content dtor, mCount->" << mCount << std::endl;
        }

        int mCount;

};


int main () {

    {
        std::deque<std::shared_ptr<Content>> myDeque;
        for (int i = 0; i < 10; ++i) {
            std::shared_ptr<Content> content(new Content(i));
            myDeque.emplace_back(content);
        }

    }

    std::cout << "out of scope" << std::endl;

    return 0;
}
