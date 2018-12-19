//
// Created by Brendan Berg on 15.12.18.
//

#include <Geometry/GeoPoint.hpp>


GeoPoint::GeoPoint ()
: m_ID(0), m_Coordinate{0.0, 0.0, 0.0}, m_End(true)
{ }


GeoPoint::GeoPoint (double end)
: m_ID(0), m_Coordinate{end, 0.0, 0.0}, m_End(true)
{ }


GeoPoint::GeoPoint (unsigned int id, double x, double y, double z)
: m_ID(id), m_Coordinate{x, y, z}, m_End(false)
{ }


double GeoPoint::GetX () const
{
    return m_Coordinate.x;
}


double GeoPoint::GetY () const
{
    return m_Coordinate.y;
}


double GeoPoint::GetZ () const
{
    return m_Coordinate.z;
}


const Point<double>& GeoPoint::GetCoordinate () const
{
    return m_Coordinate;
}


bool GeoPoint::IsEnd () const
{
    return m_End;
}


bool GeoPoint::IsCircular () const
{
    return (0.5 < m_Coordinate.x) && (m_Coordinate.x < 1.5);
}
