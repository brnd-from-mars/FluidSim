//
// Created by Brendan Berg on 19.12.18.
//

#include <Utility/Point.hpp>

#include <Graphics/RenderUtility.hpp>


RenderUtility::RenderUtility (const sf::Vector2u& windowSize,
                              const Boundary<double>& boundary)
: m_ContentBoundary(boundary)
{
    m_WindowSize = sf::Vector2f(static_cast<float>(windowSize.x),
                                static_cast<float>(windowSize.y));

    auto contentSize = boundary.GetSize();
    m_ContentSize = sf::Vector2f(static_cast<float>(contentSize.width),
                                 static_cast<float>(contentSize.height));

    CalculatePrescaleTransform();
    CalculateScaleFactor();
    CalculatePostscaleTransform();
}


void RenderUtility::CalculatePrescaleTransform ()
{
    auto centerRaw = m_ContentBoundary.GetCenterCoordinate();
    m_PrescaleTransform = sf::Vector2f(static_cast<float>(-centerRaw.x),
                                       static_cast<float>(-centerRaw.y));
}


void RenderUtility::CalculateScaleFactor ()
{
    auto factor = std::min(m_WindowSize.x / m_ContentSize.x,
                           m_WindowSize.y / m_ContentSize.y);
    m_ScaleFactor = sf::Vector2f(factor, -factor);
}


void RenderUtility::CalculatePostscaleTransform ()
{
    m_PostscaleTransform = sf::Vector2f(m_WindowSize.x / 2.0f,
                                        m_WindowSize.y / 2.0f);
}


sf::Vector2f RenderUtility::TransformPoint (sf::Vector2f point) const
{
    point += m_PrescaleTransform;
    point.x *= m_ScaleFactor.x;
    point.y *= m_ScaleFactor.y;
    point += m_PostscaleTransform;

    return point;
}


sf::Vector2f RenderUtility::TransformPoint (const Point<double>& point) const
{
    auto transform = sf::Vector2f(static_cast<float>(point.x),
                                  static_cast<float>(point.y));
    return TransformPoint(transform);
}
