
#include <thread>
#include <memory>
#include <iostream>
#include <mutex>
#include <vector>



int main()
{
	std::shared_ptr<int> ptr1(new int(42));

	auto ptr2 = std::make_shared<int>(42);

	std::cout<<*ptr1<<std::endl;

	ptr1 = ptr2;
	std::shared_ptr<int> ptr3(ptr2);
	std::shared_ptr<int> ptr4(std::move(ptr2));

	ptr1 = nullptr;
}