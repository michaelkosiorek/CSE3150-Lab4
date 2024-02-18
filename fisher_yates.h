#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array(int ary[], int len);
void swap(int *first, int *second);
void show_data(int array[], const int length);
void fisher_yates(int array[], const int length, int (* random_fcn)());
int array_sum(int arrayp[], const int length);
bool non_neg_prefix_sum(int ary[], int length);
bool non_pos_prefix_sum(int ary[], int length);

#endif