#include <iostream>
#include <thread>
#include <chrono>




void hello(int num){
		std::this_thread::sleep_for(std::chrono::seconds(num));

	std::cout<<"hello from thread"<<"\n";
}

int main(int argc, char const *argv[])
{	

	std::thread thr1(hello,1);
	std::thread thr2(hello,2);
	std::thread thr3(hello,3);

	thr1.join();
	thr2.join();
	thr3.join();





}