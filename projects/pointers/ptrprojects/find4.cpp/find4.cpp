#include <iostream>

void find4(const int* array, int size, int* low, int* high, double* avg, int* sum){
	*low = 2147483647;
	*high = -2147483647;
	*sum = 0;

	for (int i = 0; i < size; i++){
		*sum = *sum + array[i];
		if (*low > array[i]) {
		    *low = array[i];
	        }
                if (*high < array[i]) {
	            *high = array[i]; 
	        }
        }
        *avg = *sum / size;
}
int main() {

int array[11] = {5,8,64,139,1436,53671,3,56,9,81,53672 };
int n = 11;
int low;
int high;
double avg;
int sum;
find4(array,n,&low,&high,&avg,&sum);
std::cout << low << " " << high << " " << avg << " " << sum << std::endl;
std::cout << "printing addresses" << std::endl;
std::cout << "0X" << array << " " << &low << " " << &high << " " << &avg << " " << &sum << std::endl;
}	 

