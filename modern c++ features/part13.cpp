#include <iostream>
#include <chrono>
#include <vector>
#include <utility>
#include <random>

struct Point
{
	int x,y;
};




//move semantics
int main(int argc, char const *argv[]){
	
	auto ptr = std::make_unique<Point>(Point{3,6});

	std::cout<<ptr->x<<"   "<<ptr->y;



}