//
// Created by Brendan Berg on 16.12.18.
//

#include <Graphics/Renderable.hpp>

#include "Graphics/Renderable.hpp"


Renderable::Renderable (std::shared_ptr<sf::RenderWindow> window,
                        const RenderUtility& transformUtility)
: m_Window(std::move(window)), m_TransformUtility(transformUtility)
{ }
