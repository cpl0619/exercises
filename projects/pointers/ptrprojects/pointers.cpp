#include<iostream>

int main(){

	int a;
	int* aptr = &a;

	std::cout << "Enter a value for variable A" << std::endl;
	std::cin >> a;

	std::cout << "the value for A is: " << a << "stored in address: " << aptr << std::endl;

return 0;	
}
