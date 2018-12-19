//
// Created by Brendan Berg on 16.12.18.
//

#include <iostream>

#include <Graphics/RenderableGeometry.hpp>


RenderableGeometry::RenderableGeometry (sf::RenderWindow& window,
                                        const GeometrySet& geometry)
: Renderable(window), m_Geometry(geometry)
{ }


void RenderableGeometry::Draw ()
{
    auto windowSize = m_Window.getSize();
    auto geometryBoundary = m_Geometry.GetBoundary();

    if ((windowSize != m_LastWindowSize) ||
        (geometryBoundary != m_LastGeometryBoundary))
    {
        m_LastWindowSize = windowSize;
        m_LastGeometryBoundary = geometryBoundary;
        GenerateVertexArrays();
    }

    for (const auto& vertexArray : m_VertexArrays)
    {
        m_Window.draw(vertexArray);
    }
}


void RenderableGeometry::GenerateVertexArrays ()
{
    m_VertexArrays.resize(0);

    auto prescaleTransform = GetPrescaleTransform();
    auto scaleFactor = GetScaleFactor();
    auto postscaleTransform = GetPostscaleTransform();

    for (const auto& geometry : m_Geometry.GetGeometries())
    {
        m_VertexArrays.emplace_back(sf::LineStrip);

        for (const auto& point : geometry.GetPoints())
        {
            auto transformed = TransformGeoPoint(point,
                                                 prescaleTransform,
                                                 scaleFactor,
                                                 postscaleTransform);
            m_VertexArrays.back().append(transformed);
        }
    }
}


sf::Vector2f RenderableGeometry::GetGeometrySize () const
{
    auto sizeRaw = m_Geometry.GetBoundary().GetSize();
    auto geometrySize = sf::Vector2f(static_cast<float>(sizeRaw.width),
                                     static_cast<float>(sizeRaw.height));
    return geometrySize;
}


sf::Vector2f RenderableGeometry::GetTargetSize () const
{
    // TODO: replace fixed value
    auto targetSize = sf::Vector2f(m_LastWindowSize.x / 3.0f,
                                   m_LastWindowSize.y / 3.0f);
    return targetSize;
}


sf::Vector2f RenderableGeometry::GetPrescaleTransform () const
{
    auto centerRaw = m_Geometry.GetBoundary().GetCenterCoordinate();
    auto prescaleTransform = sf::Vector2f(static_cast<float>(-centerRaw.x),
                                          static_cast<float>(-centerRaw.y));
    return prescaleTransform;
}


sf::Vector2f RenderableGeometry::GetScaleFactor () const
{
    auto targetSize = GetTargetSize();
    auto geometrySize = GetGeometrySize();
    auto factor = std::min(targetSize.x / geometrySize.x,
                           targetSize.y / geometrySize.y);
    auto scaleFactor = sf::Vector2f(factor, -factor);
    return scaleFactor;
}


sf::Vector2f RenderableGeometry::GetPostscaleTransform () const
{
    auto postscaleTransform = sf::Vector2f(m_LastWindowSize.x / 2.0f,
                                           m_LastWindowSize.y / 2.0f);
    return postscaleTransform;
}


sf::Vertex
RenderableGeometry::TransformGeoPoint (const GeoPoint& point,
                                       const sf::Vector2f& prescaleTransform,
                                       const sf::Vector2f& scaleFactor,
                                       const sf::Vector2f& postscaleTransform)
{
    auto transform = sf::Vector2f(static_cast<float>(point.GetX()),
                                  static_cast<float>(point.GetY()));
    transform.x += prescaleTransform.x;
    transform.y += prescaleTransform.y;
    transform.x *= scaleFactor.x;
    transform.y *= scaleFactor.y;
    transform.x += postscaleTransform.x;
    transform.y += postscaleTransform.y;
    return sf::Vertex(transform);
}
