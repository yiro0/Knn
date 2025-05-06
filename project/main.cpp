//
// Created by Bartek
//

#include <iostream>
#include <cstring>
#include "functions_header.h"
#include "structures.h"

int main(int argc, char *argv[])
{
//    Check if the program was run with any parameters
    if (argc == 1) {
        std::cout << "Missing required command line arguments.\n"
                  << "The program is run in a command line with the switches:\n" << "-train input train dataset file\n"
                  << "-test input test dataset file\n" << "-out output file\n" << "-k number of k nearest neighbours\n"
                  << "Running the program with no parameters prints a short help how to use the program.\n";
        return 0;
    }

    std::string train_set;
    std::string test_set;
    std::string output_set;
    std::string k_set;

    /*
    'strcmp' return value indicates:
    -> <0 the first character that does not match has a lower value in ptr1 than in ptr2
    -> 0 the contents of both strings are equal
    -> >0 the first character that does not match has a greater value in ptr1 than in ptr2 */
    //So in this example we're checking if the contents of string are both equal, thus we use '== 0'

    //Parsing command line arguments
    for (int i = 0; i < argc; ++i) { //Iterating over 'command line arguments'
        if (strcmp(argv[i], "-train") == 0) {
            train_set = argv[i + 1];

        }

        if (strcmp(argv[i], "-test") == 0) {
            test_set = argv[i + 1];
        }

        if (strcmp(argv[i], "-out") == 0) {
            output_set = argv[i + 1];
        }

        if (strcmp(argv[i], "-k") == 0) {
            k_set = argv[i + 1];
        }
    }
    //If the current argument matches one of the switches (-train, -test, -out, -k) the next argument is assigned to the appropriate string.

    // Check if required parameters are present
    if (train_set.empty() || test_set.empty() || output_set.empty()) {
        std::cout << "Missing required command line arguments.\n"
                  << "The program is run in a command line with the switches:\n" << "-train input train dataset file\n"
                  << "-test input test dataset file\n" << "-out output file\n" << "-k number of k nearest neighbours\n"
                  << "Running the program with no parameters prints a short help how to use the program.\n";
        return 0;
    }

    if (k_set.empty()) {
        std::cout << "Hello k set is empty!";
    }

    int int_k = 0;
    //Try catch to check if 'k' switch works.
    try {
        int_k = std::stoi(k_set); //stoi is a function converting string to integer, if a conversion fails we know 'k' is wrong as and input from command line
    } catch (std::invalid_argument &) {
        std::cout << "Error: Invalid value for '-k' switch\n";
        return 0;
    }

    //Read input files
    sets_of_points points;
    read_file(train_set, points, false); //Read file function call,
    // points as a reference to sets_of_points structure and a boolean indicating whether the file being read is the train file.

    read_file(test_set, points, true); //Read file function call,
    // points as a reference to sets_of_points structure and a boolean indicating whether the file being read is the test file.

    //Run kNN algorithm
    points = algorithm_KNN(points, int_k); //Call of [...] function to run the kNN algorithm passing in the points structure and the value of 'k' arguments.
    print_results(output_set, points); // After running the kNN algorithm this function prints out results to file.
    return 0;
}
