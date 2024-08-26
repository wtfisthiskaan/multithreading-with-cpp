#include <iostream>
#include <chrono>
#include <vector>
#include <utility>




//move semantics
int main(int argc, char const *argv[]){

	auto add_two = [y = 2](int x){return x + y;}; // y is local lambda  

	std::cout<<add_two(2)<<"\n";
	std::cout<<add_two(5)<<"\n";

	int z = 1;

	auto add_z_plus1 = [y = z + 1](int x){ return x + y;};


	std::cout<<add_z_plus1(2)<<"\n";
	std::cout<<add_z_plus1(5)<<"\n";
}