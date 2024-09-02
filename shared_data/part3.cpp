#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex task_mutex;



void print(std::string str){
	for(int i = 0; i < 5 ; i++){
		try{
			task_mutex.lock();
			std::cout<<str[0]<<str[1]<<str[2]<<"\n";

			throw std::exception();
			task_mutex.unlock();
		}
		catch(std::exception& e){
			std::cout<<e.what()<<"\n";
		}
		
	}
}

int main(int argc, char const *argv[])
{	

	std::thread thr1(print,"abc");
	std::thread thr2(print,"xyz");
	std::thread thr3(print,"123");

	thr1.join();
	thr2.join();
	thr3.join();


}