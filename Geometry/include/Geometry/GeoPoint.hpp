//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOPOINT_HPP
#define FLUIDSIM_GEOPOINT_HPP

#include <Utility/Point.hpp>


class GeoPoint
{
public:

    GeoPoint ();

    GeoPoint (unsigned int id, double x, double y, double z);

    double GetX () const;

    double GetY () const;

    double GetZ () const;

    const Point<double>& GetCoordinate () const;

    bool IsEnd () const;


private:

    unsigned int m_ID;

    Point<double> m_Coordinate;

    bool m_End;


};


#endif //FLUIDSIM_GEOPOINT_HPP
