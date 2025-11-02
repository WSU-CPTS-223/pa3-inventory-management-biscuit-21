# PA-2-AVL-Map/CMakeLists.txt
# CMake project for PA-2-AVL-Map: includes source files and handles CSVs

cmake_minimum_required(VERSION 3.8)

# Add non-template source files to the executable
add_executable(PA-3-Inventory-Management
    main.cpp
    DataMaps.cpp
    # Add other non-template .cpp files here
)

# Set C++ standard
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PA-3-Inventory-Management PROPERTY CXX_STANDARD 20)
  set_property(TARGET PA-3-Inventory-Management PROPERTY CXX_STANDARD_REQUIRED ON)
endif()

# Copy CSVs to the top-level build folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data-1.csv DESTINATION ${CMAKE_BINARY_DIR})