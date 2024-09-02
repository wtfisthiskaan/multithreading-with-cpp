#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex task_mutex;

using namespace std::literals;

void print(std::string str){
	for(int i = 0; i < 5 ; i++){
			std::unique_lock<std::mutex> lg(task_mutex);

			std::cout<<str[0]<<str[1]<<str[2]<<"\n";

			//lg.unlock();


			std::this_thread::sleep_for(200ms);

		
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