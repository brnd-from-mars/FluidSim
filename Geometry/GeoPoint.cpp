//
// Created by Brendan Berg on 15.12.18.
//

#include <Geometry/GeoPoint.hpp>


GeoPoint::GeoPoint ()
: m_ID(0), m_X(0.0), m_Y(0.0), m_Z(0.0), m_End(true)
{

}

GeoPoint::GeoPoint (unsigned int id, double x, double y, double z)
: m_ID(id), m_X(x), m_Y(y), m_Z(z), m_End(false)
{ }


double GeoPoint::GetX () const
{
    return m_X;
}


double GeoPoint::GetY () const
{
    return m_Y;
}


double GeoPoint::GetZ () const
{
    return m_Z;
}


bool GeoPoint::IsEnd () const
{
    return m_End;
}
