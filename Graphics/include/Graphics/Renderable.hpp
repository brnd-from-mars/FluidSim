//
// Created by Brendan Berg on 16.12.18.
//

#ifndef FLUIDSIM_RENDERABLE_HPP
#define FLUIDSIM_RENDERABLE_HPP

#include <memory>

#include <SFML/graphics.hpp>

#include <Graphics/RenderUtility.hpp>


class Renderable
{
public:

    Renderable (std::shared_ptr<sf::RenderWindow> window,
                const RenderUtility& transformUtility);

    virtual ~Renderable () = default;

    virtual void Draw () = 0;


protected:

    std::shared_ptr<sf::RenderWindow> m_Window;

    const RenderUtility& m_TransformUtility;


};


#endif //FLUIDSIM_RENDERABLE_HPP
