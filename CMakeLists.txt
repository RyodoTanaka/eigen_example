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


# Compile file
set(SRC
  # 2d_transform
  orthogonal_matrix
  qr_decomposition
  skew_symmetric_matrix
  solve_formula
  diagonalization
  test
  )

foreach(src ${SRC})
  if("$src" MATCHES "qr_decomposition")
    add_executable(${src}
      src/${src}.cpp
      src/gramschmidt.hpp
      )
  else()
      add_executable(${src}
      src/${src}.cpp
      )
  endif()
  
  target_link_libraries(${src}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    python2.7
    )
  
endforeach(src)
