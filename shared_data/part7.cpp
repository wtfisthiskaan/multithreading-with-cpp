#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::timed_mutex task_mutex;

using namespace std::literals;

void task1(){
	using namespace std::literals;
	 std::this_thread::sleep_for(100ms);

	std::cout<<"task1 tries to lock"<<"\n";
	task_mutex.lock();
	std::cout<<"task1 grab the mutex"<<"\n";
	std::this_thread::sleep_for(5s);
	std::cout<<"task1 release the mutex"<<"\n";

	task_mutex.unlock();
}

void task2(){
	using namespace std::literals;

	//std::this_thread::sleep_for(100ms);

	std::cout<<"task2 tries to lock"<<"\n";

	std::unique_lock<std::timed_mutex> uLock(task_mutex);
	
	while(!uLock.try_lock_for(1s)){
		std::cout<<"task2 cannot grab the mutex"<<"\n";
		std::this_thread::sleep_for(100ms);
	}

	std::cout<<"task2 grab the mutex"<<"\n";
	std::this_thread::sleep_for(500ms);

	//task_mutex.unlock();
}

int main(int argc, char const *argv[])
{	

	std::thread thr1(task2);
	std::thread thr2(task1);
	
	thr1.join();
	thr2.join();




}