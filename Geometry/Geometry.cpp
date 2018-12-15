//
// Created by Brendan Berg on 15.12.18.
//

#include <Geometry/Geometry.hpp>

#include <iostream>
#include <limits>


Geometry::Geometry (GeoFileParser& parser)
{
    constexpr auto maxDouble = std::numeric_limits<double>::max();
    constexpr auto minDouble = std::numeric_limits<double>::lowest();
    m_MinX = maxDouble;
    m_MaxX = minDouble;
    m_MinY = maxDouble;
    m_MaxY = minDouble;

    GeoPoint gp;

    do
    {
        gp = parser.ParsePoint();
        if (!gp.IsEnd())
        {
            m_Points.push_back(gp);
            CheckBoundaries(m_Points.back());
        }
    } while(!gp.IsEnd());

#ifdef DEBUG
    std::cout << "Created Geometry " << std::endl
              << "\tPoints       : " << GetSize() << std::endl
              << "\tBoundaries X : " << m_MinX << " - " << m_MaxX << std::endl
              << "\tBoundaries Y : " << m_MinY << " - " << m_MaxY << std::endl;
#endif
}


unsigned int Geometry::GetSize () const
{
    return static_cast<unsigned int>(m_Points.size());
}


void Geometry::CheckBoundaries (const GeoPoint& point)
{
    m_MinX = std::min(m_MinX, point.GetX());
    m_MaxX = std::max(m_MaxX, point.GetX());

    m_MinY = std::min(m_MinY, point.GetY());
    m_MaxY = std::max(m_MaxY, point.GetY());
}
