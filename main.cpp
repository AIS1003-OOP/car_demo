#include <iostream>

#include <threepp/threepp.hpp>

using namespace threepp;

class Car: public Object3D, public KeyListener {

public:

    Car() {
        auto boxGeometry = BoxGeometry::create(1, 1, 1);
        auto boxMaterial = MeshBasicMaterial::create();
        boxMaterial->color = Color::red;
        auto box = Mesh::create(boxGeometry, boxMaterial);
        add(box);
    }

    void onKeyPressed(KeyEvent evt) override {
        if (evt.key == Key::W) {
            isWPressed = true;
        } else if (evt.key == Key::S) {
            isSPressed = true;
        }
    }

    void onKeyReleased(KeyEvent evt) override {
        if (evt.key == Key::W) {
            isWPressed = false;
        } else if (evt.key == Key::S) {
            isSPressed = false;
        }
    }

    void update(float dt) {
        if (isWPressed) {
            position.z += speed * dt;
        }
        if (isSPressed) {
            position.z -= speed * dt;
        }

    }

private:
    float speed = 1;

    bool isWPressed = false;
    bool isSPressed = false;
};

int main() {
    Canvas canvas("Separation of concerns");
    GLRenderer renderer(canvas.size());

    Scene scene;
    scene.background = Color::aliceblue;

    PerspectiveCamera camera(75, canvas.aspect(), 0.1, 1000);
    camera.position.z = 5;

    OrbitControls controls{camera, canvas};

    Car car;
    scene.add(car);

    canvas.addKeyListener(car);

    Clock clock;
    canvas.animate([&] {
        float dt = clock.getDelta();

        car.update(dt);
        renderer.render(scene, camera);
    });

    return 0;
}
