#ifndef SOC_DEMO_CARKEYCONTROLLER_HPP
#define SOC_DEMO_CARKEYCONTROLLER_HPP

#include <threepp/input/KeyListener.hpp>

#include "Car.hpp"

// Not necessary the best implementation, but at least it is separated from the Car class
class CarKeyController : public threepp::KeyListener {
public:
    CarKeyController(Car &car) : car(car) {
    }

    void onKeyPressed(threepp::KeyEvent evt) override {
        if (evt.key == threepp::Key::W) {
            isWPressed = true;
        } else if (evt.key == threepp::Key::S) {
            isSPressed = true;
        }
    }

    void onKeyReleased(threepp::KeyEvent evt) override {
        if (evt.key == threepp::Key::W) {
            isWPressed = false;
        } else if (evt.key == threepp::Key::S) {
            isSPressed = false;
        }
    }

    void update(float dt) {
        if (isWPressed) {
            car.driveForward(dt);
        }
        if (isSPressed) {
            car.driveBackward(dt);
        }
    }

private:
    Car &car;

    bool isWPressed = false;
    bool isSPressed = false;
};

#endif //SOC_DEMO_CARKEYCONTROLLER_HPP
