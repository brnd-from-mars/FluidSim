//
// Created by Brendan Berg on 19.12.18.
//

#ifndef FLUIDSIM_MESH_HPP
#define FLUIDSIM_MESH_HPP

#include <vector>

// TODO: add the use of multiple objects
#include <Geometry/Geometry.hpp>
#include <Utility/Boundary.hpp>
#include <Utility/Point.hpp>

#include <Mesh/MeshCell.hpp>


class Mesh
{
public:

    explicit Mesh (const Geometry& geometry);

    const Boundary<double>& GetBoundary () const;

    const std::vector<std::vector<MeshCell>>& GetMeshCells() const;


private:

    const Geometry& m_Geometry;

    Boundary<double> m_MeshBoundary;

    std::vector<std::vector<MeshCell>> m_Cells;

    void CalculateMeshBoundary (double marginX, double marginY);

    void GenerateMeshCells (unsigned int I, unsigned int J);

    void GenerateMeshCells (double dx, double dy);

    bool CellInsideGeometry (const MeshCell& cell) const;


};


#endif //FLUIDSIM_MESH_HPP
