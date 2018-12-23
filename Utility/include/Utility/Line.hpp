//
// Created by Brendan Berg on 23.12.18.
//

#ifndef FLUIDSIM_LINE_HPP
#define FLUIDSIM_LINE_HPP

#include <Utility/Point.hpp>


template <typename T>
struct Line
{
    Point<T> point1;
    Point<T> point2;

    bool Intersects(const Line<T>& rhs) const
    {
        auto point3 = rhs.point1;
        auto point4 = rhs.point2;

        auto lhsA = point2.y - point1.y;
        auto lhsB = point1.x - point2.x;
        auto lhsC = - (lhsA * point1.x + lhsB * point1.y);

        auto d1 = lhsA * point3.x + lhsB * point3.y + lhsC;
        auto d2 = lhsA * point4.x + lhsB * point4.y + lhsC;

        if (d1 > 0 && d2 > 0) return false;
        if (d1 < 0 && d2 < 0) return false;

        auto rhsA = point4.y - point3.y;
        auto rhsB = point3.x - point4.x;
        auto rhsC = - (rhsA * point3.x + rhsB * point3.y);

        auto d3 = rhsA * point1.x + rhsB * point1.y + rhsC;
        auto d4 = rhsA * point2.x + rhsB * point2.y + rhsC;

        if (d3 > 0 && d4 > 0) return false;
        if (d3 < 0 && d4 < 0) return false;

        return true;
    }


};

#endif //FLUIDSIM_LINE_HPP
