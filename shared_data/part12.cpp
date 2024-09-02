#include <iostream>
#include <thread>
#include <mutex>
#include <random>
//circular wait
using namespace std::literals;

std::mutex mt1;
std::mutex mt2;


void func(){
	std::lock_guard<std::mutex> lg(mt1);

	std::cout<<"thread a locked 1"<<std::endl;

	std::this_thread::sleep_for(500ms);

	std::lock_guard<std::mutex> lg2(mt2);
}

void func2(){
	std::lock_guard<std::mutex> lg(mt2);

	std::cout<<"thread b locked 2"<<std::endl;

	std::this_thread::sleep_for(500ms);

	std::lock_guard<std::mutex> lg2(mt1);
}


int main(int argc, char const *argv[])
{	

	std::thread thr1(func);
	std::thread thr2(func2);
	thr1.join();
	thr2.join();



}