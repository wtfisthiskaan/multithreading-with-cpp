#include <iostream>
#include <thread>

class Hello{
public:
	void operator()(){
		std::cout<<"Hello thread class"<<"\n";	
	}
};

void hello(){
	std::cout<<"Hello thread func"<<"\n";
}

int main(int argc, char const *argv[])
{	

	Hello hello;
	std::thread thr(hello);

	thr.join();


	std::thread thr2([](){
		std::cout<<"closure gibi geldi";
	});

	thr2.join();

}