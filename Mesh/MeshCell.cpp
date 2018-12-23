//
// Created by Brendan Berg on 19.12.18.
//

#include <Mesh/MeshCell.hpp>


MeshCell::MeshCell (unsigned int i,
                    unsigned int j,
                    unsigned int k,
                    const Point<double>& center)
: m_Index{i, j, i}, m_CenterCoordinate(center), m_Type(Type::normal)
{ }


void MeshCell::SetType (MeshCell::Type type)
{
    m_Type = type;
}


Point<double> MeshCell::GetCoordinate () const
{
    return m_CenterCoordinate;
}


MeshCell::Type MeshCell::GetType () const
{
    return m_Type;
}

