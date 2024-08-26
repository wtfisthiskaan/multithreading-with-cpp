#include <iostream>


void func(int i){
	std::cout<<"integerli called"<<"\n";
}

void func(int* i){
	std::cout<<"pointerli called"<<"\n";
}

int main(int argc, char const *argv[])
{	

	func(NULL);
	func(nullptr);

	return 0;
}