//
// Created by Brendan Berg on 15.12.18.
//

#include <iostream>
#include <vector>

#include <SFML/graphics.hpp>

#include <Geometry/GeometrySet.hpp>
#include <Graphics/RenderableGeometry.hpp>


// TODO: Outsource sfml to graphics component

int main ()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    auto window = sf::RenderWindow(sf::VideoMode(1200, 700),
                                   std::string("FluidSim"),
                                   sf::Style::Default,
                                   settings);

    auto geometry = GeometrySet(std::string("Geometries/airfoil2.fsg"));

    auto renderableGeometry = RenderableGeometry(window,geometry);

    while (window.isOpen())
    {
        auto event = sf::Event();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Key::Escape)
                    {
                        window.close();
                    }
                    break;
                default:
                    break;
            }
        }

        renderableGeometry.Draw();

        window.setFramerateLimit(30);
        window.display();
    }

    return 0;
}
