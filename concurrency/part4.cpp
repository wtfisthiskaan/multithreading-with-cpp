#include <iostream>
#include <thread>



void hello(std::string&& str){
	std::cout<<str;
}

int main(int argc, char const *argv[])
{	

	std::string str = "Hello from string biach!!";

	std::thread thr(hello,std::move(str));

	thr.join();

	std::cout<<(str.empty() ? "No": "Yes");
	std::cout<<str;




}