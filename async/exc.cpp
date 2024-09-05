#include <iostream>
#include <thread>
#include <future>

void producer(std::promise<int>& prom,int a,int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    prom.set_value(a+b);  
}

void consumer(std::future<int>& fut) {
    std::cout<<fut.get();
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread prodThread(producer, std::ref(prom),6,7);
    std::thread consThread(consumer, std::ref(fut));

    prodThread.join();
    consThread.join();

    return 0;
}
