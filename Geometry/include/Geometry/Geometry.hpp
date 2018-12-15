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

    unsigned int GetSize () const;

    const Boundary<double>& GetBoundary () const;


private:

    std::vector<GeoPoint> m_Points;

    Boundary<double> m_Boundary;

};


#endif //FLUIDSIM_GEOMETRY_HPP
