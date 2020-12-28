cmake_minimum_required(VERSION 3.12)
project(sampling-snippets-for-raytracing LANGUAGES CXX)

# external
add_subdirectory(external)

# sampling
add_library(sampling INTERFACE)
target_include_directories(sampling INTERFACE .)
target_compile_features(sampling INTERFACE cxx_std_17)

# pybind11
pybind11_add_module(binding python/binding.cpp)
set_target_properties(binding PROPERTIES OUTPUT_NAME "sampling")
target_link_libraries(binding PRIVATE sampling)
set_target_properties(binding PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(binding PROPERTIES CXX_EXTENSIONS OFF)

# copy build output to python/
add_custom_command(TARGET binding POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:binding>" "${PROJECT_SOURCE_DIR}/python/$<TARGET_FILE_NAME:binding>"
  COMMENT "Copying build output to python/"
)