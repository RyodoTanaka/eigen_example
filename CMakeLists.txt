cmake_minimum_required(VERSION 2.8)
project(Eigen_Example)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# For Boost
find_package(Boost COMPONENTS system REQUIRED)

# For Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# For Python
include_directories("/usr/include/python2.7")

# Original Libraries


add_executable(2d_transform
  src/2d_transform.cpp
  )


target_link_libraries(2d_transform 
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  python2.7
)

add_executable(orthogonal_matrix
  src/orthogonal_matrix.cpp
  )

target_link_libraries(orthogonal_matrix
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  python2.7
)

add_executable(qr_decomposition
  src/qr_decomposition.cpp
  )

target_link_libraries(qr_decomposition
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  python2.7
)

