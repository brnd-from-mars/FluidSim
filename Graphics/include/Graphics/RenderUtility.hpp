//
// Created by Brendan Berg on 19.12.18.
//

#ifndef FLUIDSIM_RENDERUTILITY_HPP
#define FLUIDSIM_RENDERUTILITY_HPP

#include <SFML/graphics.hpp>

#include <Utility/Boundary.hpp>
#include <Utility/Point.hpp>


// TODO: rename to transform utility
class RenderUtility
{
public:

    RenderUtility() = default;

    RenderUtility (const sf::Vector2u& windowSize,
                   const Boundary<double>& boundary);


    sf::Vector2f TransformPoint (sf::Vector2f point) const;

    sf::Vector2f TransformPoint (const Point<double>& point) const;


private:

    sf::Vector2f m_WindowSize;

    sf::Vector2f m_ContentSize;

    Boundary<double> m_ContentBoundary;

    sf::Vector2f m_PrescaleTransform;

    sf::Vector2f m_ScaleFactor;

    sf::Vector2f m_PostscaleTransform;

    void CalculatePrescaleTransform ();

    void CalculateScaleFactor ();

    void CalculatePostscaleTransform ();


};


#endif //FLUIDSIM_RENDERUTILITY_HPP
