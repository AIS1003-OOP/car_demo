#include <threepp/threepp.hpp>

#include "Car.hpp"
#include "CarKeyController.hpp"

using namespace threepp;

auto createCarMesh() {
    auto boxGeometry = BoxGeometry::create(1, 1, 1.5);
    boxGeometry->translate(0, 0.5, 0);
    auto boxMaterial = MeshBasicMaterial::create();
    boxMaterial->color = Color::red;
    return Mesh::create(boxGeometry, boxMaterial);
}

int main() {
    Canvas canvas("Separation of concerns");
    GLRenderer renderer(canvas.size());

    Scene scene;
    scene.background = Color::aliceblue;

    auto grid = GridHelper::create();
    scene.add(grid);

    PerspectiveCamera camera(75, canvas.aspect(), 0.1, 1000);
    camera.position.set(2, 2, -5);

    OrbitControls controls{camera, canvas};

    Car car;
    car.setSpeed(1);

    auto carMesh = createCarMesh();
    carMesh->position = car.getPosition();
    scene.add(carMesh);

    CarKeyController keyController(car);
    canvas.addKeyListener(keyController);

    Clock clock;
    canvas.animate([&] {
        const float dt = clock.getDelta();

        keyController.update(dt);
        carMesh->position = car.getPosition();

        renderer.render(scene, camera);
    });

    return 0;
}
