#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex task_mutex;



void task1(){
	using namespace std::literals;
	std::cout<<"task1 tries to lock"<<"\n";
	task_mutex.lock();
	std::cout<<"task1 grab the mutex"<<"\n";
	std::this_thread::sleep_for(500ms);
	std::cout<<"task1 release the mutex"<<"\n";

	task_mutex.unlock();
}

void task2(){
	using namespace std::literals;

	std::this_thread::sleep_for(100ms);

	std::cout<<"task2 tries to lock"<<"\n";
	
	while(!task_mutex.try_lock()){
		std::cout<<"task2 cannot grab the mutex"<<"\n";
		std::this_thread::sleep_for(100ms);
	}

	std::cout<<"task2 grab the mutex"<<"\n";
	std::this_thread::sleep_for(500ms);
	std::cout<<"task2 release the mutex"<<"\n";

	task_mutex.unlock();
}


int main(int argc, char const *argv[])
{	

	std::thread thr1(task1);
	std::thread thr2(task2);
	
	thr1.join();
	thr2.join();


}