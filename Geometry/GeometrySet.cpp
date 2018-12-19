//
// Created by Brendan Berg on 15.12.18.
//

#include <iostream>

#include <Geometry/GeoFileParser.hpp>

#include <Geometry/GeometrySet.hpp>


GeometrySet::GeometrySet ()
{
#ifdef DEBUG
    std::cout << "Constructed GeometrySet" << std::endl;
#endif
}


GeometrySet::GeometrySet (const std::string& filepath)
: GeometrySet()
{
    ParseFile(filepath);
}


void GeometrySet::ParseFile (const std::string& filepath)
{
    auto parser = GeoFileParser(filepath);

    while (!parser.IsEnd())
    {
        m_Geometries.emplace_back(parser);
        UpdateBoundary(m_Geometries.back());
    }

#ifdef DEBUG
    std::cout << "Added geometries to GeometrySet:" << std::endl
              << "\tBoundary X : " << m_Boundary.min.x << " - "
                                   << m_Boundary.max.x << std::endl
              << "\tBoundary Y : " << m_Boundary.min.y << " - "
                                   << m_Boundary.max.y << std::endl;
#endif
}


void GeometrySet::UpdateBoundary (const Geometry& geometry)
{
    m_Boundary = Boundary<double>::Combine(m_Boundary, geometry.GetBoundary());
}


const std::vector<Geometry>& GeometrySet::GetGeometries () const
{
    return m_Geometries;
}


const Boundary<double>& GeometrySet::GetBoundary () const
{
    return m_Boundary;
}
