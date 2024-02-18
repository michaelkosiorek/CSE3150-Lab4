#include <iostream>
#include "fisher_yates.h"

void print_array(int ary[], int len) {
    for (int i=0; i<len; i++) {
        std::cout << ary[i] << " ";
    }
    std::cout << std::endl;
}

// attemping to swap w/ nullptr's will do nothing
void swap(int *first, int *second) {
    if (first==nullptr || second==nullptr) {
        // std::cout << "You really shouldn't be doin this chief" << std::endl;
        return;
    }
    int temp = *first;
    *first = *second;
    *second = temp;
}

int random_fcn() {
    return rand();
}

void show_data(int array[], const int length) {
  for (int i=0; i < length; i++) {
    std::cout << array[i] << " ";
  }
}

void fisher_yates(int array[], const int length, int (* random_func)()) {
  for (int i=0; i < length-1; i++) {
    int random_idx = random_fcn() % (length-i); // gives random index within our range
    swap(&array[i], &array[random_idx + i]);
  }
}

int array_sum(int array[], const int length) {
    int sum=0;
    for (int i=0; i < length; i++) sum += array[i];
    return sum;
}

bool non_neg_prefix_sum(int ary[], int length) {
    int sum=0;
    for(int i=0; i<length; i++) {
        sum += ary[i];
        if (sum < 0) return false;
    }
    return true;
}

// returns true if prefix sum of ary is never positive
bool non_pos_prefix_sum(int ary[], int length) {
    int sum=0;
    for (int i=0; i < length; i++) {
        sum += ary[i];
        if (sum > 0) return false;
    }
    return true;
}