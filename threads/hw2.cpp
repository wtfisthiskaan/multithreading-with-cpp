#include <iostream>
#include <thread>
#include <chrono>


int var = 0;

void increment(){
	for(int i = 0; i < 100000 ; i++){
		var++;
	}
}

int main(int argc, char const *argv[])
{	

	std::thread thr1(increment);
	std::thread thr2(increment);
	std::thread thr3(increment);

	thr1.join();
	thr2.join();
	thr3.join();

	std::cout<<var;





}