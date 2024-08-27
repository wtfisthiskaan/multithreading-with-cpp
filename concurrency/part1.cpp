#include <iostream>
#include <thread>

/*
Server waits for a client to connect. When a new client connects, server immediately creates a new child process to handle clients requests. And server goes back to wait a new
client connection.

It might be hard to organize and coordinate threads when we creating concurrent structure with threads or processes etc.
Coding is hard. 
*/

void hello(){
	std::cout<<"Hello thread"<<"\n";
}

int main(int argc, char const *argv[])
{	

	std::thread thr(hello);
	thr.join();
	std::cout<<"deneme";
}