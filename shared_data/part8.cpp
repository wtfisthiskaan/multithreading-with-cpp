#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <string>

std::shared_mutex mut;

int x = 0;

void write(){
	std::lock_guard<std::shared_mutex> lg(mut);

	x++;
}


void read(){
	std::shared_lock<std::shared_mutex> lg(mut);

	using namespace std::literals;
	std::cout<<x;
	std::this_thread::sleep_for(100ms);
}

int main(int argc, char const *argv[])
{	
	std::vector<std::thread> threads;

	for(int i = 0; i < 20; i++){
		threads.push_back(std::thread(read));
	}

	for(int i = 0; i < 2; i++){
		threads.push_back(std::thread(write));
	}

	for(int i = 0; i < 20; i++){
		threads.push_back(std::thread(read));
	}

	for(auto& thr: threads){
		thr.join();
	}
	


}