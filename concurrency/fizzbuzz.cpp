#include <iostream>
#include <thread>

void fizzbuzz(){
	std::vector<std::string> names{"Abdul","Bart","Claudia","Divya"};

	int nameIndex,num = 1;

	while(1){
		nameIndex = (num - 1) % 4;

		if(num % 5 == 0 && num % 3 == 0){
			std::cout<<names[nameIndex]<<" says fizzbuzz!"<<"\n";
		}
		else if(num % 3 == 0){
			std::cout<<names[nameIndex]<<" says fizz!"<<"\n";
		}
		else if(num % 5 == 0){
			std::cout<<names[nameIndex]<<" says buzz!"<<"\n";
		}
		else{
			std::cout<<names[nameIndex]<<" says "<<num<<"\n";
		}

		num++;

	}
}

int main(int argc, char const *argv[])
{	

	std::thread thr(fizzbuzz);

	thr.join();
}