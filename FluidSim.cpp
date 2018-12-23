//
// Created by Brendan Berg on 15.12.18.
//

#include <iostream>
#include <vector>

#include <Geometry/GeometrySet.hpp>
#include <Mesh/Mesh.hpp>
#include <Graphics/RenderController.hpp>


int main ()
{
    auto geometry = GeometrySet(std::string("Geometries/square.fsg"));

    auto mesh = Mesh(geometry.GetGeometries().front());

    auto renderController = RenderController(1200, 800,
                                             std::string("Fluid Simulation"),
                                             mesh.GetBoundary());

    renderController.CreateGeometryRenderer(geometry);
    renderController.CreateMeshRenderer(mesh);

    while (renderController.IsRunning())
    {
        renderController.Draw();
    }

    return 0;
}
