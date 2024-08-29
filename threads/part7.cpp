#include <iostream>
#include <thread>
#include <chrono>

class thread_guard{
	std::thread thr;
public:
	explicit thread_guard(std::thread&& thr): thr(std::move(thr)){}

    ~thread_guard(){
    	if(thr.joinable()) thr.join();
    }

    thread_guard(const thread_guard&) = delete;
    thread_guard& operator= (const thread_guard&) = delete;

};


void hello(){
	std::cout<<"hello from thread"<<"\n";
}

int main(int argc, char const *argv[])
{	

	std::cout<<"thread started"<<"\n";

	try{
		 std::thread thr(hello);
		 thread_guard(std::move(thr));
		throw std::exception();


	}
	catch(std::exception& e){
		std::cout<<"exception "<<e.what()<<"\n";
	}





}