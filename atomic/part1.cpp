#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>
#include <atomic>

int counter = 0;

void task(){
	for(int i = 0; i < 100000;i++){
		counter += 1;
	}
}


int main()
{	
	std::vector<std::thread> tasks;
	// Start the threads
	for (int i = 0; i < 10; ++i)
	{
		tasks.push_back(std::thread(task));
	}

	for(auto& task: tasks)
		task.join();

	std::cout<<counter;
}