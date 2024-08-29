#include <iostream>
#include <thread>
#include <chrono>



void hello(){
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout<<"hello from thread"<<"\n";


	try{
		throw std::exception();
	}
	catch(std::exception& e){
		std::cout<<"exception "<<e.what()<<"\n";
	}

	return;
}

std::thread func(){
	std::thread thr(hello);

	return thr;
}

int main(int argc, char const *argv[])
{	
	std::thread thr = func();

	std::cout<<"threads id is"<<thr.get_id();

	thr.join();

	



}