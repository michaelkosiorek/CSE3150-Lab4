#ifndef _MAKE_WELL_BALANCED_H_
#define _MAKE_WELL_BALANCED_H_

#include <vector>

int get_lowest_idx_first_occurrence(int ary[], int length);
std::vector<int> generate_well_balanced_vector(std::vector<int> vector_to_modify, int array_provided[], const int length);
void print_vector(std::vector<int>);


#endif