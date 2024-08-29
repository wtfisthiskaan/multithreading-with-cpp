#include <iostream>
#include <thread>
#include <chrono>



void hello(){
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout<<"hello from thread"<<"\n";
}

int main(int argc, char const *argv[])
{	

	std::cout<<"thread started"<<"\n";
	std::thread thr(hello);

	thr.join();




}