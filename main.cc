#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "SortingAlgorithms/sorts.hh"
#include "SortingAlgorithms/mergeSort.hh"
#include "SortingAlgorithms/heapSort.hh"
#include "SortingAlgorithms/quickSort.hh"
#include "SortingAlgorithms/bubbleSort.hh"
#include "SortingAlgorithms/insertionSort.hh"
#include "SortingAlgorithms/selectionSort.hh"
#include "SortingAlgorithms/countingSort.hh"
#include "SortingAlgorithms/bogoSort.hh"
#include "energyReadings.hh"
#include "stamp.hh"
#include "helperFunctions.hh"

#define DELAY 2

void measureFunctionPerformance(int numberOfSorts, void (*fns[])(double[],int), std::string fnNames[], std::vector<int> sizes, std::ofstream& outfile){
  for(int size : sizes){
    //EnergyArrays *arrays = getEnergySamples(size, DELAY);
    double *data = new double[size];
    genRandomArray(data, size);
    double *copy = new double[size];
    for(int i = 0; i < numberOfSorts; i++){
      if((fnNames[i] == "Bubble_Sort" || fnNames[i] == "Insertion_Sort" || fnNames[i] == "Selection_Sort") && size > 50000){ // don't bother with these for big arrays
        continue;
      }
      makeCopy(copy, data, size);
      Stamp start;
      fns[i](copy, size);
      Stamp stop;
      double time_elapsed;
      if (fnNames[i] == "BOGO_Sort") time_elapsed = stop.timeDifference(start); // higher granularity because small sizes 1-5 go by really quick
      else time_elapsed = stop.timeDifference(start) / 1000000;
      std::vector<double> energy_diff = stop.energyDifference(start);
<<<<<<< HEAD
      std::cout << fnNames[i] << " " << size << " " << time_elapsed << " " ;
=======
      //std::cout << fnNames[i] << " " << size << std::setprecision(20) << " "  << time_elapsed << " " ;
      outfile << fnNames[i] << " " << size << std::setprecision(20) << " "  << time_elapsed << " " ;
>>>>>>> b94f1138ecd4623c44c1aad4141dafe691d321f5
      printVector(energy_diff);
    }
    delete[] copy;
    delete[] data;
    //delete arrays 
  } 
}

int main(int argc, char *argv[]){
  ProfileInit();

  int numberOfSorts = 7;
  void (*fns[])(double[],int ) = {bubbleSort, insertionSort, selectionSort, countingSort, mergeSort, mergeSortOpt, heapSort};
  std::string fnNames[] = {"Bubble_Sort", "Insertion_Sort", "Selection_Sort", "Counting_Sort", "Merge_Sort", "Optimized_Mergesort", "Heap_Sort"};
  std::vector<int> sizes = {10, 20, 30, 40 ,50 , 60, 70, 80, 90, 100,200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
  std::ostream outfile(argv[1]);
  measureFunctionPerformace(numberOfSorts, fns, fnNames, sizes, outfile);

  //bonus: Bogo Sort!
  std::ostream bogoOut = ("bogoOutput.data");
  void (*bogo[])(double[],int) = {bogoSort};
  std::string bogoName[] = {"BOGO_Sort"};
  std::vector<int> bogoSizes = {1,2,3,4,5,6,7,8,9,10,11,12}; // 12 is already pushing it with this one ...
  measureFunctionPerformance(1, bogo, bogoName, bogoSizes, bogoOut);

  ProfileDealloc();

  return 0;
}
