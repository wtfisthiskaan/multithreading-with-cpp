#include <iostream>
#include <chrono>
#include <vector>

class Test{};

void func(const Test& test){
	std::cout<<"L value";
}

void func(const Test&& test){
	std::cout<<"R value";
}

//move semantics
int main(int argc, char const *argv[]){
	Test test;

	func(test);

	func(Test());
	
	func(std::move(test));



	//func(a);
}