//
// Created by Brendan Berg on 16.12.18.
//

#ifndef FLUIDSIM_RENDERABLE_HPP
#define FLUIDSIM_RENDERABLE_HPP

#include <SFML/graphics.hpp>


class Renderable
{
public:

    explicit Renderable (sf::RenderWindow& window);

    virtual void Draw () = 0;


protected:

    sf::RenderWindow& m_Window;


};


#endif //FLUIDSIM_RENDERABLE_HPP
