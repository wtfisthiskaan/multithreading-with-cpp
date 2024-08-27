#include <iostream>
#include <thread>



void hello(std::string str){
	std::cout<<str;
}

int main(int argc, char const *argv[])
{	

	std::thread thr(hello,"Helloooooooo biaachhh!!");

	thr.join();



}