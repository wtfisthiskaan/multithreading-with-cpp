#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>
#include <future>

using namespace std::literals;


void task(){
	for(int i = 0; i < 100000;i++){
//		counter += 1;
	}
}


int main()
{	
	std::packaged_task<int(int,int)> ptask([](int a,int b){
		std::this_thread::sleep_for(2s);
		return a + b;
	});

	std::future<int> fut = ptask.get_future();

	ptask(6,7);

	std::cout<<fut.get();
}
