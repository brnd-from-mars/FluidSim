//
// Created by Brendan Berg on 19.12.18.
//

#ifndef FLUIDSIM_MESHCELL_HPP
#define FLUIDSIM_MESHCELL_HPP

#include <Utility/Point.hpp>


class MeshCell
{
public:

    enum class Type
    {
        normal,
        inactive,
        inlet,
        outlet,
        wall
    };

    MeshCell (unsigned int i,
              unsigned int j,
              unsigned int k,
              const Point<double>& center);

    void SetType (Type type);

    Point<double> GetCoordinate () const;

    Type GetType () const;


private:

    Point<unsigned int> m_Index;

    Point<double> m_CenterCoordinate;

    Type m_Type;


};


#endif //FLUIDSIM_MESHCELL_HPP
