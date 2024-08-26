#include <iostream>
#include <chrono>
#include <vector>



int main(int argc, char const *argv[]){//lambdalari neden kullaniriz??
	int n = 5;
	auto lam = [&n](int arg){return ++n * 2 * arg;};

	std::vector<int> v{1,2,3,4,5};

	int radix = 3;

	auto n_even = std::count_if(v.begin(),v.end(),
		[radix](int x){
			std::cout<<x<<"\n";
			return x%radix == 0;}
		);

	std::cout<<n_even;

}