//
// Created by Brendan Berg on 15.12.18.
//

#ifndef FLUIDSIM_POINT_HPP
#define FLUIDSIM_POINT_HPP


template <typename T>
struct Point
{
    union
    {
        T x;
        T width;
    };

    union
    {
        T y;
        T height;
    };

    union
    {
        T z;
        T depth;
    };

    bool operator== (const Point<T>& rhs) const
    {
        return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
    }

    bool operator!= (const Point<T>& rhs) const
    {
        return !(*this != rhs);
    }


};


#endif //FLUIDSIM_POINT_HPP
