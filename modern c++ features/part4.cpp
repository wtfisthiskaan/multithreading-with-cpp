#include <iostream>
#include <chrono>
#include <vector>



int main(int argc, char const *argv[])
{// auto will ignore any reference and const initializers

	std::vector<int> v{1,2,3,4,5};

	for(auto it = v.begin(); it != v.end(); it++){
		*it *= 2; 
	}


	for(auto it = v.begin(); it != v.end(); it++){
		std::cout<<*it;
	}

	for(auto& i:v){
		i += 2;
	}

	for(auto i:v){
		std::cout<<i;
	}

	return 0;
}