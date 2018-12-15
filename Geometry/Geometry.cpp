//
// Created by Brendan Berg on 15.12.18.
//

#include <iostream>

#include <Geometry/Geometry.hpp>


Geometry::Geometry (GeoFileParser& parser)
{
    GeoPoint geoPoint;

    do
    {
        geoPoint = parser.ParsePoint();
        if (!geoPoint.IsEnd())
        {
            m_Points.push_back(geoPoint);
            m_Boundary.EnlargeToPoint(m_Points.back().GetCoordinate());
        }
    } while(!geoPoint.IsEnd());

#ifdef DEBUG
    std::cout << "Constructed Geometry " << std::endl
              << "\tPoints       : " << GetSize() << std::endl
              << "\tBoundary X : " << m_Boundary.min.x << " - "
                                   << m_Boundary.max.x << std::endl
              << "\tBoundary Y : " << m_Boundary.min.y << " - "
                                   << m_Boundary.max.y << std::endl;
#endif
}


unsigned int Geometry::GetSize () const
{
    return static_cast<unsigned int>(m_Points.size());
}


const Boundary<double>& Geometry::GetBoundary () const
{
    return m_Boundary;
}
