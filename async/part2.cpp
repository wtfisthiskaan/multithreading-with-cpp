#include <iostream>
#include <thread>
#include <thread>
#include <future>

unsigned long long fibonacci(unsigned long long n){
    if(n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    //std::async(hello);
    auto result = std::async(fibonacci,44);

    bool finished = false;

    using namespace std::literals;

    while(result.wait_for(1s) != std::future_status::ready){
        std::cout<<"being ready..\n";
    }

    std::cout<<result.get();

    return 0;
}
