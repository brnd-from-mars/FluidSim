//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOMETRY_HPP
#define FLUIDSIM_GEOMETRY_HPP

#include <vector>

#include <Utility/Boundary.hpp>
#include <Utility/Point.hpp>

#include <Geometry/GeoFileParser.hpp>
#include <Geometry/GeoPoint.hpp>


class Geometry
{
public:

    explicit Geometry (GeoFileParser& parser);

    unsigned int GetPointNumber () const;

    const std::vector<GeoPoint>& GetPoints () const;

    const Boundary<double>& GetBoundary () const;


private:

    std::vector<GeoPoint> m_Points;

    Boundary<double> m_Boundary;

    void AppendPoint (const GeoPoint& point);

};


#endif //FLUIDSIM_GEOMETRY_HPP
