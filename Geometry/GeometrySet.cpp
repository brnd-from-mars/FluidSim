//
// Created by Brendan Berg on 15.12.18.
//

#include <Geometry/GeometrySet.hpp>

#include <Geometry/GeoFileParser.hpp>


GeometrySet::GeometrySet (const std::string& filepath)
{
    ParseFile(filepath);
}


void GeometrySet::ParseFile (const std::string& filepath)
{
    auto parser = GeoFileParser(filepath);

    while (!parser.IsEnd())
    {
        m_Geometries.emplace_back(parser);
    }
}
