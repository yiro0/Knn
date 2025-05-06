/** @file structures.h */
//
// Created by Bartek on 04/02/2023.
//
#ifndef INC_2A61D9D6_GR04_REPO_STRUCTURES_H
#define INC_2A61D9D6_GR04_REPO_STRUCTURES_H

#include <vector>
#include <string>

 /**
    * @file
	* @brief Contains structures for storing sets of labeled points
	*/

 /**
  * @struct point
  * @brief structure representing
  */
struct point 
{
    std::string label;     ///< The label of the point
    std::vector<double> coordinates; ///< The coordinates of the point in n-dimensional space
};

/**
 * @struct sets_of_points
 * @brief Structure representing sets of labeled points for training and testing
 */
struct sets_of_points {
    std::vector<point> points_train; ///< The set of points used for training
    std::vector<point> points_test;  ///< The set of points used for testing
};
#endif //INC_2A61D9D6_GR04_REPO_STRUCTURES_H
