//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOMETRY_HPP
#define FLUIDSIM_GEOMETRY_HPP

#include <vector>

#include <Geometry/GeoFileParser.hpp>
#include <Geometry/GeoPoint.hpp>


class Geometry
{
public:

    explicit Geometry (GeoFileParser& parser);

    unsigned int GetSize () const;


private:

    std::vector<GeoPoint> m_Points;

    double m_MinX;

    double m_MaxX;

    double m_MinY;

    double m_MaxY;

    void CheckBoundaries (const GeoPoint& point);

};


#endif //FLUIDSIM_GEOMETRY_HPP
