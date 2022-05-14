#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "ant.hpp"
#include "colony.hpp"
#include "food.hpp"
#include "pheromone.hpp"
#include "pheromone_map.hpp"

const unsigned int HEIGHT = 500;
const unsigned int WIDTH = 500;
const unsigned int FPS = 60;

const unsigned int ANTCOUNT = 100;

int main(int argc, char* argv[]) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ants", sf::Style::Close, settings);
    window.setFramerateLimit(FPS);  // Limit FPS

    double t = 0.0;         // Verstrichene Zeit in ms
    double dt = 1.0 / FPS;  // Schrittweite in ms

    PheromoneMap pheromones;
    std::vector<std::unique_ptr<Ant>> ants;  // Use pointer bc we can't instatiate abstract classes
    ants.reserve(ANTCOUNT);

    std::shared_ptr<Colony> colony = std::make_shared<Colony>(WIDTH / 2, HEIGHT / 2);
    std::shared_ptr<Food> foodA = std::make_shared<Food>(50, 50);

    for (int i = 0; i < ANTCOUNT; ++i) {
        ants.push_back(std::make_unique<Ant>(pheromones));
    }
    for (std::unique_ptr<Ant> const& ant : ants) {
        ant->addToUmwelt(colony);
        ant->addToUmwelt(foodA);
    }

    while (window.isOpen()) {
        // Main event loop

        sf::Event event {};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update
        t += dt;
        pheromones.update();
        for (std::unique_ptr<Ant> const& obj : ants) {
            obj->update();
        }
        for (Pheromone& pheromone : pheromones.pheromones) {
            pheromone.update();
        }

        // Render
        window.clear(sf::Color::White);
        for (Pheromone& pheromone : pheromones.pheromones) {
            window.draw(pheromone.appearance);
        }
        for (std::unique_ptr<Ant> const& obj : ants) {
            window.draw(obj->appearance);
        }
        window.draw(colony->appearance);
        window.draw(foodA->appearance);
        window.display();
    }

    std::cout << "Simulation Beendet nach " << t << " Sekunden!" << std::endl;
    return 0;
}
