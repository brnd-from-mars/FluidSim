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

    RenderableGeometry (sf::RenderWindow& window,
                        const GeometrySet& geometry);

    void Draw () override;


private:

    const GeometrySet& m_Geometry;

    sf::Vector2u m_LastWindowSize;

    Boundary<double> m_LastGeometryBoundary;

    std::vector<sf::VertexArray> m_VertexArrays;

    void GenerateVertexArrays ();

    sf::Vector2f GetGeometrySize () const;

    sf::Vector2f GetTargetSize () const;

    sf::Vector2f GetPrescaleTransform () const;

    sf::Vector2f GetScaleFactor () const;

    sf::Vector2f GetPostscaleTransform () const;

    sf::Vertex TransformGeoPoint (const GeoPoint& point,
                                  const sf::Vector2f& prescaleTransform,
                                  const sf::Vector2f& scaleFactor,
                                  const sf::Vector2f& postscaleTransform);


};


#endif //FLUIDSIM_RENDERABLEGEOMETRY_HPP
