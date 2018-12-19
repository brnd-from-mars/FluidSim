//
// Created by Brendan Berg on 15.12.18.
//

#include <iostream>

#include <Geometry/Geometry.hpp>


Geometry::Geometry (GeoFileParser& parser)
{
    GeoPoint geoPoint;

    bool atEnd = false;

    while (!atEnd)
    {
        geoPoint = parser.ParsePoint();
        if (geoPoint.IsEnd())
        {
            if (geoPoint.IsCircular())
            {
                AppendPoint(m_Points.front());
            }

            atEnd = true;
        }
        else
        {
            AppendPoint(geoPoint);
        }
    }

#ifdef DEBUG
    std::cout << "Constructed Geometry " << std::endl
              << "\tPoints       : " << GetPointNumber() << std::endl
              << "\tBoundary X : " << m_Boundary.min.x << " - "
                                   << m_Boundary.max.x << std::endl
              << "\tBoundary Y : " << m_Boundary.min.y << " - "
                                   << m_Boundary.max.y << std::endl;
#endif
}


unsigned int Geometry::GetPointNumber () const
{
    return static_cast<unsigned int>(m_Points.size());
}


const std::vector<GeoPoint>& Geometry::GetPoints () const
{
    return m_Points;
}


const Boundary<double>& Geometry::GetBoundary () const
{
    return m_Boundary;
}


void Geometry::AppendPoint (const GeoPoint& point)
{
    m_Points.push_back(point);
    m_Boundary.EnlargeToPoint(point.GetCoordinate());
}
