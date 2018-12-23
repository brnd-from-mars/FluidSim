//
// Created by Brendan Berg on 16.12.18.
//

#ifndef FLUIDSIM_RENDERABLEGEOMETRY_HPP
#define FLUIDSIM_RENDERABLEGEOMETRY_HPP

#include <vector>

#include <SFML/graphics.hpp>

#include <Geometry/GeometrySet.hpp>
#include <Utility/Boundary.hpp>

#include <Graphics/Renderable.hpp>


class RenderableGeometry : public Renderable
{
public:

    RenderableGeometry (std::shared_ptr<sf::RenderWindow> window,
                        const RenderUtility& transformUtility,
                        const GeometrySet& geometry);

    void Draw () override;


private:

    const GeometrySet& m_Geometry;

    sf::Vector2u m_LastWindowSize;

    Boundary<double> m_LastGeometryBoundary;

    std::vector<sf::VertexArray> m_VertexArrays;

    void GenerateVertexArrays ();


};


#endif //FLUIDSIM_RENDERABLEGEOMETRY_HPP
