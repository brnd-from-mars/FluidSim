//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_GEOPOINT_HPP
#define FLUIDSIM_GEOPOINT_HPP


class GeoPoint
{
public:

    GeoPoint ();

    GeoPoint (unsigned int id, double x, double y, double z);

    double GetX () const;

    double GetY () const;

    double GetZ () const;

    bool IsEnd () const;


private:

    unsigned int m_ID;

    double m_X;

    double m_Y;

    double m_Z;

    bool m_End;


};


#endif //FLUIDSIM_GEOPOINT_HPP
