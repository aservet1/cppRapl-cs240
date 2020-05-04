#include "main.hh"



int main(int argc, char *argv[])
{
	Stamp start;

	ProfileInit();
	//auto e = getEnergySamples(100000,2);
	//e->printArrays();
	void (*fns[])(double[],int ) = {bubbleSort, insertionSort, mergeSort, mergeSortOpt, quickSort, quickSort_optimized};

	auto fnNames = {"Bubble Sort", "Insertion Sort", "Merge Sort", "Optimized Mergesort", "Quicksort", "Quicksort Optimized"};
	for(const char* name : fnNames){
		std::cout << name << std::endl;
	}
	
	ProfileDealloc();

	Stamp stop;

	auto time_elapsed = stop.timeDifference(start);
	std::vector<double> energy_diff = stop.energyDifference(start);

	std::cout << "time " << time_elapsed << std::endl;
	printVector(energy_diff);
	
	return 0;
}
