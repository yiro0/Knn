//
// Created by Bartek on 14/02/2023.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "functions_header.h"
#include "structures.h"

void read_file(const std::string& file_name, sets_of_points& points, const bool is_test_file) {
//file_name, a constant reference to a string that specifies the name of the file to be read
//points, a reference to a sets_of_points structure that holds the points read from the file
//is_test_file, a boolean that specifies whether the file being read is a test file or not.

    std::ifstream filestream(file_name);
    if (filestream.is_open()) {
        std::string line;
        while (std::getline(filestream, line))
        {
            size_t pos = line.find_first_of("%");
            if (pos != std::string::npos) {
                line = line.substr(0, pos); //removes everything after '%' so from 'position 0'
            }
            if (not line.empty()) {
                std::stringstream iss(line);
                std::string label;
                double x;
                point p;
                if (!is_test_file) //If not file
                {
                    iss >> label;
                    p.label = label;
                }
                while (iss >> x) 
                        p.coordinates.push_back(x);
                   
                if (!is_test_file) //Based on this if function adds the point structure to either points_train or points_test
                    points.points_train.push_back(p);
                else 
                    points.points_test.push_back(p);
            }
        }
        filestream.close();
    }
}
