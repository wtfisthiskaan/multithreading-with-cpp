#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <string>


class Singleton {
	static Singleton* single;
public:
	Singleton(){
		std::cout<<"initing singleton"<<std::endl;
	}



    // Delete the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(const Singleton&&) = delete;


    // Static method to access the singleton instance
    static Singleton* getInstance();

    // Example method to demonstrate functionality
    void showMessage() {
        std::cout << "Hello, I am a Singleton!" << std::endl;
    }
};

Singleton* Singleton::getInstance(){
	if(single == nullptr){
		single = new Singleton;
	}
		return single;

}

Singleton& get_singleton(){
	static Singleton single;
	return single;
}

Singleton* Singleton::single = nullptr;



void task(){
	Singleton& single = get_singleton();
	std::cout<<&single<<std::endl;
}

int main(){
	std::vector<std::thread> v;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back(std::thread(task));
	}

	for(auto& thr:v){
		thr.join();
	}
}
