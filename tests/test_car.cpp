#include "Car.hpp"
#include <vector>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Car initial position") {
    std::vector<threepp::Vector3> initialPositions = {
        {1, 0, 3},
        {2, 0, 4},
        {-100, 0, 45},
        {-6, 0, -100}
    };

    std::vector<Car> cars;

    for (auto pos : initialPositions) {
        cars.emplace_back(pos);
    }

    for (int i = 0; i < cars.size(); i++) {
        CHECK(cars[i].getPosition() == initialPositions[i]);
    }
}

TEST_CASE("Car can drive forward and backward", "[Car]") {
    threepp::Vector3 initialPos{0, 0, 0};

    Car car(initialPos);
    car.setSpeed(2);

    REQUIRE(car.getPosition() == initialPos);

    car.driveForward(1.5f);
    REQUIRE(car.getPosition() == threepp::Vector3(0, 0, 3));

    car.driveBackward(0.5f);
    REQUIRE(car.getPosition() == threepp::Vector3(0, 0, 2));
}
