#ifndef COUNTING_SORT_HH
#define COUNTING_SORT_HH

#include <iostream>
#include <cfloat>
#include <cmath>

#define flag(n) std::cout << "flag" << n << std::endl;

template <typename E>
static E findMax(E arr[], int length){
  E max = -9999999;
  for (int i = 0; i < length; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

template <typename E>
static int hash(E d){
  return d * 10000;
}
// the hashing function exists because we know E will be a double for the purposes of this project
// we need to map it to an int, so multiply / divide by 10000. there is a loss of precision inherent
// in the hashing algorithm if the float extends farther than 5 decimal places, so that's a tradeoff
// that you need to be willing to make if you use this sort
template <typename E>
static E unhash(E i){
  return i / 10000;
}

template <typename E>
void countingSort(E arr[], int length){
  E max = findMax(arr, length);
  int buckets_length = hash(max) + 1;
  int buckets[buckets_length];
  for (int i = 0; i < buckets_length; i++){
    buckets[i] = 0;
  }
  for (int i = 0; i < length; i++){
    int index = hash(arr[i]);
    buckets[index] += 1;
  }
  int arr_i = 0;
  for (int i = 0; i < buckets_length; i++){
    while (buckets[i] != 0){
      arr[arr_i++] = unhash((E)i);
      buckets[i] -= 1;
    }
  }
}

#endif
