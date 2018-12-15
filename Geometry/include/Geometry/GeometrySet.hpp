//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOMETRYSET_HPP
#define FLUIDSIM_GEOMETRYSET_HPP

#include <string>
#include <vector>

#include <Geometry/Geometry.hpp>


class GeometrySet
{
public:

    explicit GeometrySet (const std::string& filepath);

    void ParseFile (const std::string& filepath);


private:

    std::vector<Geometry> m_Geometries;


};


#endif //FLUIDSIM_GEOMETRYSET_HPP
