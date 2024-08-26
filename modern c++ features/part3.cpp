#include <iostream>
#include <chrono>


namespace sc = std::chrono;

int main(int argc, char const *argv[])
{	

	sc::seconds(2);
	std::cout<<"a";
	sc::seconds(20);
		std::cout<<"a";
	sc::microseconds(100);
		std::cout<<"a";


	using namespace std::literals;
	2s;
		std::cout<<"a";

	return 0;
}