#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"
#include "make_well_balanced.h"

int array1[] = {1, -1, -1, 1, 1, -1, 1, -1, -1};
int array1_len = 9;
int array1_lowest_depth_idx_actual=2;

int array2[] = {1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1};
int array2_len = 11;
int array2_lowest_depth_idx_actual=10;

int array3[] = {-1, 1, 1, 1, 1, -1, -1, -1, 1, 1, 1};
int array3_len = 11;
int array3_lowest_depth_idx_actual=0;

int array4[] = {};
int array4_len = 0;
int array4_lowest_depth_idx_actual=0;

TEST_CASE("fisher-yates") {

    SUBCASE("get lowest depth function") {

        CHECK_EQ(get_lowest_idx_first_occurrence(array1, array1_len), array1_lowest_depth_idx_actual);
        CHECK_EQ(get_lowest_idx_first_occurrence(array2, array2_len), array2_lowest_depth_idx_actual);
        CHECK_EQ(get_lowest_idx_first_occurrence(array3, array3_len), array3_lowest_depth_idx_actual);
        CHECK_EQ(get_lowest_idx_first_occurrence(array4, array4_len), array4_lowest_depth_idx_actual);

    };

    SUBCASE("basic medium sized well balanced testing") {
        int test_arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        int test_arr1_len = 17;

        int iterations=10000;
        int *well_balanced_array;
        std::vector<int> well_balanced_vector;

        for (int i=0; i < iterations; i++) { // 10,000 iterations of mixing and attempting to make a non-negative prefix sum vector

            fisher_yates(test_arr1, test_arr1_len, rand);

            well_balanced_vector.clear();
            well_balanced_vector = generate_well_balanced_vector(well_balanced_vector, test_arr1, test_arr1_len);
            // print_vector(well_balanced_vector);

            well_balanced_array = well_balanced_vector.data();

            CHECK(non_neg_prefix_sum(well_balanced_array, test_arr1_len-1));

        }
    };

    SUBCASE("empty array well balanced testing") {
        int test_arr2[] = {};
        int test_arr2_len = 0;

        int iterations=10000;
        int *well_balanced_array;
        std::vector<int> well_balanced_vector;

        for (int i=0; i < iterations; i++) { // 10,000 iterations of mixing and attempting to make a non-negative prefix sum vector

            fisher_yates(test_arr2, test_arr2_len, rand);

            well_balanced_vector.clear();
            well_balanced_vector = generate_well_balanced_vector(well_balanced_vector, test_arr2, test_arr2_len);
            // print_vector(well_balanced_vector);

            well_balanced_array = well_balanced_vector.data();

            CHECK(non_neg_prefix_sum(well_balanced_array, test_arr2_len-1));
        }
    };

    SUBCASE("quite long array well balanced testing") {

        int test_arr3[2001];

        for (int i = 0; i < 1000; ++i) test_arr3[i] = 1;
        for (int i = 0; i < 1001; ++i) test_arr3[1000 + i] = -1;

        int test_arr3_len = 2001;

        int iterations=5000;
        int *well_balanced_array;
        std::vector<int> well_balanced_vector;

        for (int i=0; i < iterations; i++) { // 10,000 iterations of mixing and attempting to make a non-negative prefix sum vector

            fisher_yates(test_arr3, test_arr3_len, rand);

            well_balanced_vector.clear();
            well_balanced_vector = generate_well_balanced_vector(well_balanced_vector, test_arr3, test_arr3_len);
            // print_vector(well_balanced_vector);

            well_balanced_array = well_balanced_vector.data();

            CHECK(non_neg_prefix_sum(well_balanced_array, test_arr3_len-1));
        }
    };

}