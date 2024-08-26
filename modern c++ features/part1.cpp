#include <iostream>



int main(int argc, char const *argv[])
{	



	int x{7};

	std::cout<<x;
	
	std::string a{"Bana diyorken herkes disrespectful"};

	std::cout<<a;

	std::vector<int> v{1,2,3,4,5};

	for(int i = 0;i < v.size(); i++){
		std::cout<<v[i]<<std::endl;
	}
	





	return 0;
}