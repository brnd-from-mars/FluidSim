//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOFILEPARSER_HPP
#define FLUIDSIM_GEOFILEPARSER_HPP

#include <fstream>
#include <string>

#include <Geometry/GeoPoint.hpp>


class GeoFileParser
{
public:

    explicit GeoFileParser(const std::string& filepath);

    const std::string& GetFilepath () const;

    const std::string& GetFilename () const;

    unsigned int GetCurrentGeoLine () const;

    bool IsEnd () const;

    GeoPoint ParsePoint ();


private:

    std::string m_Filepath;

    std::string m_Filename;

    std::ifstream m_File;

    unsigned int m_CurrentGeoLine;

    bool m_End;

    std::string ParseElement (std::string& line) const;

};


#endif //FLUIDSIM_GEOFILEPARSER_HPP
