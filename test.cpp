#include <iostream>
#include "sort.h"

using namespace std;


int	main(void){
	int	a[] = { 4,8,7,6,9,5,2,3,1 };

	//BubbleSort(a, 9);
	//InserSort(a, 9);
	//ChooseSort(a, 9);
	
	//ShellSort(a, 9);
	QuickSort(a, 9);

	//MergerSort(a, 9);

	print(a, 9);

	return EXIT_SUCCESS;
}
