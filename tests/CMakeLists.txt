
add_executable(test_car test_car.cpp)
target_link_libraries(test_car PRIVATE threepp::threepp Catch2::Catch2WithMain)
target_include_directories(test_car PRIVATE "${CMAKE_SOURCE_DIR}/include")
add_test(NAME test_car COMMAND test_car)