//#define BOOST_PYTHON_STATIC_LIB

#include <iostream>
#include <boost/signals2.hpp>
#include <functional>

#include <string>
#include <mutex>
#include <thread>

void slot_1(std::string s){
    std::cout << "slot_1" << std::endl;
    std::cout << s << std::endl;
}

std::string slot_2(std::string s){
    std::cout << "slot_2" << std::endl;
    std::cout << s << std::endl;
    return "slot_2_return_value";
}


struct World {
    void set(std::string msg) {
        this->msg = msg;
    }

    std::string greet() {
        return msg;
    }

    std::string msg;
};



class HelloObject {
public:
    HelloObject() = default;

    HelloObject(const HelloObject& obj) { };

    void using_signal_sg_1(std::function<void(std::string)> slot) {
        sg_1.connect(slot);
    }

    void using_signal_sg_2(std::function<std::string(std::string)> slot) {
        sg_2.connect(slot);
    }

    void run() {
        std::thread t(std::bind(&HelloObject::fun_, this));
//        std::thread t1(std::bind(&HelloObject::fun_, this));
        t.join();
//        t1.join();
    }

    int get_counter(){
        return counter;
    }

    struct World world(){
        struct World w;
        return w;
    }

private:
    void fun_() {
        for (int i = 0; i < 100000; ++i) {
            std::lock_guard<std::mutex> lc(m);
            counter++;
//            std::cout << i << std::endl;
        }
        sg_2("正向计数...");
        for (int i = 100000; i > 0; --i) {
            std::lock_guard<std::mutex> lc(m);
            counter++;
//            std::cout << i << std::endl;
        }
        sg_1("反向计数...");
        std::cout << hello() << std::endl;
    }

    std::string hello() {
        std::cout << "hello object" << std::endl;
        return "hello object";
    }

private:
    boost::signals2::signal<void(std::string)> sg_1;
    boost::signals2::signal<std::string(std::string)> sg_2;
    int counter = 0;
    std::mutex m;
};

void hello(){
    std::cout << "Hello function" << std::endl;
}


int main() {
    HelloObject ho;

//    ho.using_signal_sg_1( std::bind(slot_1, std::placeholders::_1) );
//    ho.using_signal_sg_2( std::bind(slot_2, std::placeholders::_1) );

    ho.run();

    std::cout << ho.get_counter() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    int i =0;
//    std::cin >> i;
    return 0;
}
