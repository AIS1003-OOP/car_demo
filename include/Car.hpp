#ifndef SOC_DEMO_CAR_HPP
#define SOC_DEMO_CAR_HPP

#include <threepp/math/Vector3.hpp>


class Car {
public:
    Car(const threepp::Vector3 initialPos = {})
        : position_(initialPos) {
    }

    void driveForward(float dt) {
        position_.z += speed_ * dt;
    }

    void driveBackward(float dt) {
        position_.z -= speed_ * dt;
    }

    threepp::Vector3 getPosition() {
        return position_;
    }

    void setSpeed(float speed) {
        speed_ = speed;
    }

private:
    float speed_ = 1;
    threepp::Vector3 position_;
};

#endif //SOC_DEMO_CAR_HPP
