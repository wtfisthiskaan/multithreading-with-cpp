#include <iostream>
#include <thread>


class greeter{
public:
	void hello(){
		std::cout<<"hello from greeter";
	}
};

int main(int argc, char const *argv[])
{	
	greeter gr;

	std::thread thr(&greeter::hello, &gr);

	thr.join();


	int i = 0;

	std::thread thr2([&i](){
		i += 2;
	});

	thr2.join();

	std::cout<<i;
}