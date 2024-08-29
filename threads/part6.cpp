#include <iostream>
#include <thread>
#include <chrono>



void hello(){
	std::cout<<"hello from thread"<<"\n";
}

int main(int argc, char const *argv[])
{	

	std::cout<<"thread started"<<"\n";

	try{
		 std::thread thr(hello);
		throw std::exception();

			thr.join();

	}
	catch(std::exception& e){
		std::cout<<"exception "<<e.what()<<"\n";
	}





}