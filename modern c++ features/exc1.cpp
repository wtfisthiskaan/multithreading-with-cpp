#include <iostream>
#include <chrono>
#include <vector>
#include <utility>
#include <random>

int main(int argc, char const *argv[]){
	int x{7};
	std::string str("Let us begin");

	std::vector<int> v{4,2,3,5,1};

	for(auto i : v){
		std::cout<<i<<"\n";
	}


	auto a = &x;

	std::cout<<a;
}