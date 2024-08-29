#include <iostream>
#include <thread>



void hello(){
	std::cout<<"Hello thread"<<"\n";
}

int main(int argc, char const *argv[])
{	

	std::thread thr(hello);

	std::cout<<"Hello thread has a native handle: "<<thr.native_handle()<<"\n";
	thr.join();

		std::cout<<"Hello thread has a native handle afta join: "<<thr.native_handle()<<"\n";

}