//
// Created by Brendan Berg on 19.12.18.
//

#ifndef FLUIDSIM_RENDERCONTROLLER_HPP
#define FLUIDSIM_RENDERCONTROLLER_HPP

#include <memory>
#include <vector>

#include <SFML/graphics.hpp>

#include <Geometry/GeometrySet.hpp>
#include <Mesh/Mesh.hpp>
#include <Utility/Boundary.hpp>

#include <Graphics/Renderable.hpp>
#include <Graphics/RenderUtility.hpp>


class RenderController
{
public:

    // TODO: create window setup struct
    RenderController (unsigned int windowWidth,
                      unsigned int windowHeight,
                      const std::string& windowTitle,
                      const Boundary<double>& contentBoundary);

    void CreateGeometryRenderer (const GeometrySet& geometry);

    void CreateMeshRenderer (const Mesh& mesh);

    bool IsRunning ();

    void Draw ();


private:

    std::shared_ptr<sf::RenderWindow> m_Window;

    RenderUtility m_TransformUtility;

    std::vector<std::unique_ptr<Renderable>> m_Renderables;


};


#endif //FLUIDSIM_RENDERCONTROLLER_HPP
