#include <iostream>
#include "make_well_balanced.h"


int get_lowest_idx_first_occurrence(int ary[], int length) {

    int lowest_sum_idx=0;
    int cur_sum=0;
    int lowest_sum=0;

    for (int i=0; i < length; i++) {
        cur_sum += ary[i];
        if (cur_sum < lowest_sum) {
            lowest_sum = cur_sum;
            lowest_sum_idx = i;
        }
    }

    return lowest_sum_idx;

}

std::vector<int> generate_well_balanced_vector(std::vector<int> vector_to_modify, int array_provided[], const int length) {

    int end_of_p1 = get_lowest_idx_first_occurrence(array_provided, length);

    int p1[end_of_p1]; // not + 1 because we are throwing out the last element of p1, because it will be negative
    int p2[length-end_of_p1-1];

    for(int i=0; i < end_of_p1; i++) {
        p1[i] = array_provided[i];
    }

    for (int array_provided_idx=end_of_p1+1, p2_idx=0; array_provided_idx < length; array_provided_idx++, p2_idx++) {
        p2[p2_idx] = array_provided[array_provided_idx];
    }

    for (int p2_idx = 0; p2_idx < length-end_of_p1-1; p2_idx++) {
        vector_to_modify.push_back(p2[p2_idx]);
    }

    for (int p1_idx = 0; p1_idx < end_of_p1; p1_idx++) {
        vector_to_modify.push_back(p1[p1_idx]);
    }

    //print_vector(vector_to_modify);
    return vector_to_modify;

}

void print_vector(std::vector<int> vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}