//
// Created by Brendan Berg on 15.12.18.
//

#include <Geometry/Geometry.hpp>


Geometry::Geometry (GeoFileParser& parser)
{
    GeoPoint gp;

    do
    {
        gp = parser.ParsePoint();
        if (!gp.IsEnd())
        {
            m_Points.push_back(gp);
        }
    } while(!gp.IsEnd());
}


unsigned int Geometry::GetSize () const
{
    return static_cast<unsigned int>(m_Points.size());
}
