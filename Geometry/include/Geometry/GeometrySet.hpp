//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOMETRYSET_HPP
#define FLUIDSIM_GEOMETRYSET_HPP

#include <string>
#include <vector>

#include <Utility/Boundary.hpp>

#include <Geometry/Geometry.hpp>


class GeometrySet
{
public:

    GeometrySet ();

    explicit GeometrySet (const std::string& filepath);

    void ParseFile (const std::string& filepath);

    const std::vector<Geometry>& GetGeometries() const;

    const Boundary<double>& GetBoundary () const;


private:

    std::vector<Geometry> m_Geometries;

    Boundary<double> m_Boundary;

    void UpdateBoundary (const Geometry& geometry);


};


#endif //FLUIDSIM_GEOMETRYSET_HPP
