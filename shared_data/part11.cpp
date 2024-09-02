#include <iostream>
#include <thread>
#include <mutex>
#include <random>


class Test{
public:
	Test(){
		std::cout<<"Test cons called"<<std::endl;
	}

	void func(){

	}
};


Test* ptest = nullptr;

std::once_flag ptest_flag;

void process(){
	std::call_once(ptest_flag,[](){
		ptest = new Test;
	});

	ptest->func();
}

int main(int argc, char const *argv[])
{	

	std::thread thr1(process);
	thr1.join();

	std::cout<<std::endl;


}