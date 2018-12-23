//
// Created by Brendan Berg on 16.12.18.
//

#include <iostream>

#include <Graphics/RenderableGeometry.hpp>


RenderableGeometry::RenderableGeometry (std::shared_ptr<sf::RenderWindow> window,
                                        const RenderUtility& transformUtility,
                                        const GeometrySet& geometry)
: Renderable(std::move(window), transformUtility), m_Geometry(geometry)
{ }


void RenderableGeometry::Draw ()
{
    auto windowSize = m_Window->getSize();
    auto geometryBoundary = m_Geometry.GetBoundary();

    // TODO: Outsource change recognition to utility class
    if ((windowSize != m_LastWindowSize) ||
        (geometryBoundary != m_LastGeometryBoundary))
    {
        m_LastWindowSize = windowSize;
        m_LastGeometryBoundary = geometryBoundary;
        GenerateVertexArrays();
    }

    for (const auto& vertexArray : m_VertexArrays)
    {
        m_Window->draw(vertexArray);
    }
}


void RenderableGeometry::GenerateVertexArrays ()
{
    m_VertexArrays.resize(0);

    for (const auto& geometry : m_Geometry.GetGeometries())
    {
        m_VertexArrays.emplace_back(sf::LineStrip);

        for (const auto& point : geometry.GetPoints())
        {
            // TODO: rename GetCoordinate to plural form
            auto transformed =
                m_TransformUtility.TransformPoint(point.GetCoordinate());
            m_VertexArrays.back().append(sf::Vertex(transformed));
        }
    }
}
