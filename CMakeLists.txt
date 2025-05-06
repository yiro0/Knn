cmake_minimum_required(VERSION 3.23)
project(2a61d9d6_gr04_repo)

set(CMAKE_CXX_STANDARD 14)


#add_executable(2a61d9d6_gr04_repo
#        lab-02/tasks/ConsoleApplication1/ConsoleApplication1/ConsoleApplication1.cpp project/main.cpp lab-08/tasks/main.cpp lab-08/tasks/functions.cpp)

add_executable(2a61d9d6_gr04_repo project/main.cpp project/functions_header.h project/test.txt project/train.txt project/structures.h project/output.txt project/algorithm_knn.cpp project/read_file.cpp)

#add_custom_target(project/test.txt)
#add_executable(2a61d9d6_gr04_repo
#        lab-06/task/sources/functions.cpp lab-06/task/sources/functions.h lab-06/task/sources/main.cpp )