#include "Point.hpp"



int main() {
    // Set the size of the 2D space
    double width = 800.0;
    double height = 600.0;

    // Number of points and collision radius
    int numPoints = 5;
    double radius = 20.0;

    // Create a vector to store the points
    std::vector<Point> points(numPoints);

    // Initialize the points with random positions and velocities
    for (int i = 0; i < numPoints; ++i) {
        points[i].x = static_cast<double>(std::rand()) / RAND_MAX * width;
        points[i].y = static_cast<double>(std::rand()) / RAND_MAX * height;
        points[i].dx = (static_cast<double>(std::rand()) / RAND_MAX - 0.5) * 5.0; // Random velocity between -2.5 and 2.5
        points[i].dy = (static_cast<double>(std::rand()) / RAND_MAX - 0.5) * 5.0; // Random velocity between -2.5 and 2.5
    }

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(width, height), "Point Collision Simulation");
    
    // Set the frame rate limit (optional)
    window.setFramerateLimit(60);

    // Simulation loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move the points and check for collisions
        for (int i = 0; i < numPoints; ++i) {
            movePoint(points[i], width, height);

            for (int j = i + 1; j < numPoints; ++j) {
                if (checkCollision(points[i], points[j], radius)) {
                    std::cout << "Collision detected between point " << i << " and point " << j << std::endl;
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the points as circles
        for (const auto& point : points) {
            sf::CircleShape circle(radius);
            circle.setPosition(point.x - radius, point.y - radius);
            circle.setFillColor(sf::Color::Red);
            window.draw(circle);
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
