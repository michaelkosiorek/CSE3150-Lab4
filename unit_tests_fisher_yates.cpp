#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"

int array0[] = {};
int array1[] = {-1, 1};
int array1_sum_expected=0;

int first1 = -99;
int second1 = 4;
int save_first1 = first1;
int save_second1 = second1;

int array2[] = {2, 18, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int array2_sum_expected=121;
int array2_length=25;

TEST_CASE("fisher-yates") {

    SUBCASE("swap tests") {
        
        swap(&first1, &second1);
        CHECK_EQ(save_first1, second1);
        CHECK_EQ(save_second1, first1);

        // swapping back test
        swap(&first1, &second1);
        CHECK_EQ(save_first1, first1);
        CHECK_EQ(save_second1, second1);

        // array-swapping
        swap(&array1[0], &array1[1]);
        CHECK_EQ(array1[1], -1);
        CHECK_EQ(array1[0], 1);

        // array-swapping back
        swap(&array1[0], &array1[1]);
        CHECK_EQ(array1[1], 1);
        CHECK_EQ(array1[0], -1);

        swap(nullptr, nullptr); // would love to learn about exceptions to handle stuff like this
    };

    SUBCASE("fisher-yates function") {

        // sum of array1 should be zero every time.
        int num_trials=1000;
        int array1_sum_actual=0;
        for (int i=0; i < num_trials; i++) {
            fisher_yates(array1, 2, rand);
            array1_sum_actual=array1[0] + array1[1];
            CHECK_EQ(array1_sum_actual, array1_sum_expected);
        }

        // more complex array fisher-yates
        int array2_sum_actual;
        for (int j=0; j < num_trials; j++) {
            fisher_yates(array2, array2_length, rand);
            array2_sum_actual = array_sum(array2, array2_length);
            CHECK_EQ(array2_sum_actual, array2_sum_expected);
        }

    };

    SUBCASE("fisher-yates large") {
        int large_array_size = 1000;
        int large_array[large_array_size];
        for (int i = 0; i < large_array_size; i++) {
            large_array[i] = i+1;
        }
        int large_array_sum=500'500;

        fisher_yates(large_array, large_array_size, rand);
        CHECK_EQ(array_sum(large_array, large_array_size), large_array_sum);

        // should work again and again
        fisher_yates(large_array, large_array_size, rand);
        CHECK_EQ(array_sum(large_array, large_array_size), large_array_sum);

        fisher_yates(large_array, large_array_size, rand);
        CHECK_EQ(array_sum(large_array, large_array_size), large_array_sum);
    };
}

