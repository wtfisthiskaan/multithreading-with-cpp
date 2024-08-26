#include <iostream>
#include <chrono>
#include <vector>
#include <utility>
#include <random>

std::mt19937 mt;


//move semantics
int main(int argc, char const *argv[]){
	std::cout<<"5 rand objects"<<"\n";
	std::uniform_int_distribution<int> uid(0,100);

	for(int i = 0; i < 5; i++){
		std::cout<<uid(mt)<<"\n";
	}



}