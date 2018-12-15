//
// Created by Brendan Berg on 15.12.18.
//

#include <array>
#include <iostream>

#include <Geometry/GeoFileParser.hpp>


GeoFileParser::GeoFileParser (const std::string& filepath)
: m_Filepath(filepath), m_Filename(filepath), m_File(filepath),
  m_CurrentGeoLine(1), m_End(false)
{
    auto pos1 = m_Filepath.find_last_of('/');
    auto pos2 = m_Filepath.find_last_of('.');
    if (pos1 != std::string::npos)
    {
        pos1++;
        m_Filename = m_Filepath.substr(pos1, pos2 - pos1);
    }


#ifdef DEBUG
    std::cout << "Constructed GeoFileParser " << std::endl
              << "\tFilepath : " << m_Filepath << std::endl
              << "\tFilename : " << m_Filename << std::endl;
#endif
}


const std::string& GeoFileParser::GetFilepath () const
{
    return m_Filepath;
}


const std::string& GeoFileParser::GetFilename () const
{
    return m_Filename;
}


unsigned int GeoFileParser::GetCurrentGeoLine () const
{
    return m_CurrentGeoLine;
}


bool GeoFileParser::IsEnd () const
{
    return m_End || !m_File.good();
}


GeoPoint GeoFileParser::ParsePoint ()
{
    std::string fileline;
    auto geoPoint = GeoPoint();

    if (!m_End)
    {
        if (std::getline(m_File, fileline))
        {
            ParseElement(fileline);

            auto id = static_cast<unsigned int>(
                std::stoi(ParseElement(fileline)));

            if (id != 0)
            {
                auto point = std::array<double, 3>();
                for (auto& coord : point)
                {
                    coord = std::stod(ParseElement(fileline));
                }

                geoPoint = GeoPoint(id, point[0], point[1], point[2]);
            }
            else
            {
                m_CurrentGeoLine++;
            }
        }
        else
        {
            m_End = true;
        }
    }

    return geoPoint;
}


std::string GeoFileParser::ParseElement (std::string& line) const
{
    auto pos = line.find('\t');
    auto element = line.substr(0, pos);

    if (pos == std::string::npos)
    {
        line = std::string();
    }
    else
    {
        line = line.substr(pos + 1);
    }

    return element;
}
