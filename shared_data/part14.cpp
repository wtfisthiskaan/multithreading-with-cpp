#include <iostream>
#include <thread>
#include <mutex>

#include <random>
//circular wait
using namespace std::literals;

std::mutex mt1;
std::mutex mt2;


void func(){
	std::lock(mt1,mt2);

	std::cout<<"thread a locked 1"<<std::endl;

	std::unique_lock<std::mutex> ul1(mt1,std::adopt_lock);
	std::unique_lock<std::mutex> ul2(mt2,std::adopt_lock);

	std::this_thread::sleep_for(500ms);

}

void func2(){
	std::lock(mt1,mt2);

	std::cout<<"thread b locked 2"<<std::endl;

	std::unique_lock<std::mutex> ul1(mt1,std::adopt_lock);
	std::unique_lock<std::mutex> ul2(mt2,std::adopt_lock);

	std::this_thread::sleep_for(500ms);

}


int main(int argc, char const *argv[])
{	

	std::thread thr1(func);
	std::thread thr2(func2);
	thr1.join();
	thr2.join();



}