#include <iostream>
#include <thread>



void hello(std::string& str){
	str = "xyz";
}

int main(int argc, char const *argv[])
{	

	std::string str = "abc";

	std::thread thr(hello,std::ref(str));

	thr.join();

	std::cout<<str; 




}