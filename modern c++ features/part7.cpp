#include <iostream>
#include <chrono>
#include <vector>

void func(int&& a){
	std::cout<<a<<"\n";
}

void func2(std::vector<std::string>&& v){
	std::cout<<v.size();
}

//move semantics
int main(int argc, char const *argv[]){
	func(2);

	int a = 2;

	std::vector<std::string> v(1000000);

	std::cout<<v.size();

	func2(std::move(v));

	std::cout<<v.size();



	//func(a);
}