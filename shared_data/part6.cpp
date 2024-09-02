#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::recursive_mutex rmut;

using namespace std::literals;

int factorial(int n){
	if(n == 0 || n == 1){
		std::cout<<"returning";
		return 1;
	}

	rmut.lock();
	int rval = n * factorial(n-1);
	std::cout<<"returning"<<rval<<"\n";

	rmut.unlock();

	return rval;


}

int main(int argc, char const *argv[])
{	

	std::thread thr1(factorial,6);


	thr1.join();



}