//
// Created by Brendan Berg on 19.12.18.
//

#include <iostream>

#include <Utility/Line.hpp>

#include <Mesh/Mesh.hpp>


Mesh::Mesh (const Geometry& geometry)
: m_Geometry(geometry)
{
    CalculateMeshBoundary(1.0, 4.0);
    GenerateMeshCells(3.0, 3.0);


#ifdef DEBUG
    std::cout << "Constructed Mesh" << std::endl
              << "\tBoundary X : " << m_MeshBoundary.min.x << " - "
              << m_MeshBoundary.max.x << std::endl
              << "\tBoundary Y : " << m_MeshBoundary.min.y << " - "
              << m_MeshBoundary.max.y << std::endl
              << "\tCells X    : " << m_Cells.size() << std::endl
              << "\tCells Y    : " << m_Cells.front().size() << std::endl;
#endif
}


const Boundary<double>& Mesh::GetBoundary () const
{
    return m_MeshBoundary;
}


const std::vector<std::vector<MeshCell>>& Mesh::GetMeshCells () const
{
    return m_Cells;
}


void Mesh::CalculateMeshBoundary (double marginX, double marginY)
{
    auto geometryBoundary = m_Geometry.GetBoundary();
    auto geometrySize = geometryBoundary.GetSize();

    auto margin = Point<double>{marginX * geometrySize.width,
                                marginY* geometrySize.height,
                                0.0};

    m_MeshBoundary.min.x = geometryBoundary.min.x - margin.width;
    m_MeshBoundary.max.x = geometryBoundary.max.x + margin.width;

    m_MeshBoundary.min.y = geometryBoundary.min.y - margin.height;
    m_MeshBoundary.max.y = geometryBoundary.max.y + margin.height;
}


void Mesh::GenerateMeshCells (unsigned int I, unsigned int J)
{
    auto meshSize = m_MeshBoundary.GetSize();

    auto dx = meshSize.width / I;
    auto dy = meshSize.height / J;

    auto center = Point<double>{0.0, 0.0, 0.0};

    m_Cells.reserve(I);

    for (unsigned int i = 0; i < I; ++i)
    {
        m_Cells.emplace_back();
        m_Cells.back().reserve(J);

        for (unsigned int j = 0; j < J; ++j)
        {
            center.x = m_MeshBoundary.min.x + i * dx + 0.5 * dx;
            center.y = m_MeshBoundary.min.y + j * dy + 0.5 * dy;

            m_Cells.back().emplace_back(i, j, 0, center);
            auto& cell = m_Cells.back().back();

            if (CellInsideGeometry(cell))
            {
                cell.SetType(MeshCell::Type::inactive);
            }
            else
            {
                if (j == 0 || j == (J - 1))
                {
                    cell.SetType(MeshCell::Type::inactive);
                }
                else if (i == 0)
                {
                    cell.SetType(MeshCell::Type::inlet);
                }
                else if (i == (I - 1))
                {
                    cell.SetType(MeshCell::Type::outlet);
                }
                else
                {
                    cell.SetType(MeshCell::Type::normal);
                }
            }
        }
    }

    for (unsigned int i = 0; i < I; ++i)
    {
        for (unsigned int j = 0; j < J; ++j)
        {
            if (m_Cells[i][j].GetType() == MeshCell::Type::normal)
            {
                bool flag = false;

                if (i != 0)
                {
                    if (m_Cells[i-1][j].GetType() == MeshCell::Type::inactive)
                    {
                        flag = true;
                    }
                }
                if (j != 0)
                {
                    if (m_Cells[i][j-1].GetType() == MeshCell::Type::inactive)
                    {
                        flag = true;
                    }
                }
                if (i != (I - 1))
                {
                    if (m_Cells[i+1][j].GetType() == MeshCell::Type::inactive)
                    {
                        flag = true;
                    }
                }
                if (j != (J - 1))
                {
                    if (m_Cells[i][j+1].GetType() == MeshCell::Type::inactive)
                    {
                        flag = true;
                    }
                }

                if (flag)
                {
                    m_Cells[i][j].SetType(MeshCell::Type::wall);
                }
            }
        }
    }
}


void Mesh::GenerateMeshCells (double dx, double dy)
{
    auto meshSize = m_MeshBoundary.GetSize();

    auto I = static_cast<unsigned int>(meshSize.width / dx);
    auto J = static_cast<unsigned int>(meshSize.height / dy);

    GenerateMeshCells(I, J);
}


bool Mesh::CellInsideGeometry (const MeshCell& cell) const
{
    auto point = cell.GetCoordinate();

    if (!m_Geometry.GetBoundary().ContainsPoint(point))
    {
        return false;
    }

    auto e = 0.1 * m_Geometry.GetBoundary().GetSize().width;
    auto rayStart = Point<double>{m_Geometry.GetBoundary().min.x - e, point.y};
    auto ray = Line<double>{rayStart, point};

    auto polygon = m_Geometry.GetPoints();

    unsigned int intersects = 0;

    for (int i = 0; i < (polygon.size() - 1); ++i)
    {
        auto line = Line<double>{polygon[i].GetCoordinate(),
                                 polygon[i + 1].GetCoordinate()};

        if (ray.Intersects(line))
        {
            intersects++;
        }

    }

    return intersects % 2 != 0;
}
