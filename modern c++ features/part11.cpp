#include <iostream>
#include <chrono>
#include <vector>
#include <utility>




//move semantics
int main(int argc, char const *argv[]){

	std::vector<std::string> strings(5);

	std::cout<<"Capture by ref";

	[&strings](){
		std::cout<<"size in lambda "<<strings.size()<<"\n";
	}();

	std::cout<<"size in main "<<strings.size()<<"\n";


	[vec_strings = std::move(strings)](){
		std::cout<<"size in lambda2 "<<vec_strings.size()<<"\n";
	}();

	std::cout<<"size in main2 "<<strings.size()<<"\n";

}