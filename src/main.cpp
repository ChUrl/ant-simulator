#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "ant.hpp"
#include "colony.hpp"

const unsigned short HEIGHT = 500;
const unsigned short WIDTH = 500;
const unsigned short FPS = 60;

const unsigned short ANTCOUNT = 50;

int main(int argc, char *argv[]) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ants", sf::Style::Close, settings);
    window.setFramerateLimit(FPS); // Limit FPS

    float t = 0.0;        // Verstrichene Zeit in ms
    float dt = 1.0 / FPS; // Schrittweite in ms

    Pheromones pheromones = Pheromones();
    const Colony colony = Colony(WIDTH / 2, HEIGHT / 2);
    const Food foodA = Food(50, 50);

    std::vector<Ant> ants;
    ants.reserve(ANTCOUNT);
    for (int i = 0; i < ANTCOUNT; ++i) {
        ants.push_back(Ant(pheromones, colony));
    }

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update
        t += dt;
        for (unsigned long i = 0; i < ants.size(); ++i) {
            ants[i].update();
        }
        pheromones.update();

        // Render
        window.clear(sf::Color::White);
        window.draw(pheromones.map);
        for (Ant const& ant: ants) {
            window.draw(ant.appearance);
        }
        window.draw(colony.appearance);
        window.display();
    }

    std::cout << "Simulation Beendet nach " << t << " Sekunden!" << std::endl;
    return 0;
}
