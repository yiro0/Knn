//
// Created by Bartek on 05/02/2023.
//
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "functions_header.h"
#include "structures.h"


#define debug(x) std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << (x) << std::endl 

sets_of_points algorithm_KNN(sets_of_points points, int k_value) //The input parameters to the function algorithm_KNN are a sets_of_points structure and an integer k_value.
// K_value is the parameter that specifies the number of nearest neighbours to consider when classifying the test points.
{
    int k = k_value;
    std::vector<point> points_train = points.points_train;
    std::vector<point> points_test = points.points_test;
    int n_train = points_train.size();
    int n_test = points_test.size();

    for (int i = 0; i < n_test; i++)  //Function that iterates over each point in 'test set' and calculates the Euclidean distance between that point and all points in the 'training set'. "Octopus :)"
    {
        std::vector<std::pair<double, std::string>> distances;  // od punktu i-tego w teście do pozostalych w trainie
        for (int j = 0; j < n_train; j++) 
        {
            double sq_distance = 0;
            
            for (int d = 0; d < points_test[i].coordinates.size(); d++) 
            {
                sq_distance += pow(points_test[i].coordinates[d] - points_train[j].coordinates[d], 2);
            }
            distances.push_back(std::make_pair(sqrt(sq_distance), points_train[j].label)); //Storing the distances along with the label of the training point in a vector of pairs.
        }
        
        sort(distances.begin(), distances.end()); //function sorts the vector of pairs in ascending order based on the distance.
        
        std::unordered_map<std::string, int> label_count; //Unordered map works superfast
        for (int j = 0; j < k; j++) //This loop iterates over the k nearest neighbors to the i-th test point and updates the frequency count of their labels in the label_count map.
            // Specifically, it uses the label of each of the k nearest neighbors to increment the count of that label in the map.
        {
            label_count[distances[j].second]++;
        }
        std::string majority_label; //label_count will contain a count of the labels of the k nearest neighbors. This loop finds the most frequent label among them by iterating over the elements of label_count.
        // Specifically, it initializes a max_count variable to 0 and a majority_label variable to an empty string.
        // Then, for each element in the label_count map, it checks if the count of the label is greater than the current maximum count, and if so,
        // updates the max_count variable and sets the majority_label to the label that has the highest count.
        int max_count = 0;
        for (auto label: label_count) {
            if (label.second > max_count) {
                max_count = label.second;
                majority_label = label.first;
            }
        }
        debug(majority_label);
        points_test[i].label = majority_label; //Finally, the code assigns the majority_label found in the previous loop to the i-th test point's label attribute.
        // This will assign the predicted label to the test point, based on the labels of the k nearest neighbors in the training set.
    }
    sets_of_points labeled_points; //Finally, the predicted label is assigned to the corresponding point in the test set, and the labeled sets_of_points structure is returned by the function.
    labeled_points.points_train = points_train;
    labeled_points.points_test = points_test;
    return labeled_points;
}
///do pliku!!!!
//Printing out to file with taking a reference over an object sets_of_points structure, which contains two vectors of point objects: points_train and points_test.
void print_results(const std::string& file_name, const sets_of_points& labeled_points) {
    std::ofstream output_file;
    output_file.open(file_name);
    if (output_file.is_open()){
        for (const auto &point : labeled_points.points_test) {
            output_file << point.label << " ";
            for (const auto & d : point.coordinates)
                output_file << d << " ";
            output_file << std::endl; //<<'\n';
        }
    } else {
        std::cout << "Unable to open/create file" << "output.txt" << std::endl;
    }
    output_file.close();
}


