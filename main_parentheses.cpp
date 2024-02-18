#include <iostream>
#include <cstdlib>
#include <vector>

#include "fisher_yates.h"
#include "make_well_balanced.h"

using namespace std;

int main() {
    string n_string;
    cout << "Enter the number of open-parens: " << endl;
    cin >> n_string;

    int n = stoi(n_string);

    // cout << n << endl;

    int array_values[2*n + 1];

    for (int i=0; i < n; i++) {
        array_values[i] = 1;
    }

    for (int i=0; i < n+1; i++) {
        array_values[i+n] = -1;
    }

    print_array(array_values, 2*n + 1);

    srand(2024);

    int iterations=100000;
    std::vector<int> well_balanced_vector;
    int *well_balanced_array;

    for (int i=0; i < iterations; i++) {

        fisher_yates(array_values, 2*n + 1, rand);

        well_balanced_vector.clear();
        well_balanced_vector = generate_well_balanced_vector(well_balanced_vector, array_values, 2*n + 1);
        print_vector(well_balanced_vector);

        well_balanced_array = well_balanced_vector.data();

        // shouldn't happen, must be checked to test.
        if (!(non_neg_prefix_sum(well_balanced_array, 2*n))) {
            cout << "Imbalanced array above." << endl;
            return -1;
        }

        /*
        for (int i=0; i < 2*n; i++) {
            std::cout << well_balanced_array[i] << " ";
        }
        std::cout << std::endl;
        */
    }



    return 0;
}