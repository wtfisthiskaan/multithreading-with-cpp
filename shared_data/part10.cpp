#include <iostream>
#include <thread>
#include <mutex>
#include <random>

 std::mt19937 mt;



void print(){
	std::uniform_real_distribution<double> dist(0,1);

	for (int i = 0; i < 10; ++i)
	{
		std::cout<<dist(mt)<<std::endl;
	}
}

int main(int argc, char const *argv[])
{	

	std::thread thr1(print);
	thr1.join();

	std::cout<<std::endl;
	std::thread thr2(print);
	thr2.join();

}