//
// Created by Brendan Berg on 19.12.18.
//

#ifndef FLUIDSIM_RENDERABLEMESH_HPP
#define FLUIDSIM_RENDERABLEMESH_HPP

#include <SFML/graphics.hpp>

#include <Mesh/Mesh.hpp>

#include <Graphics/Renderable.hpp>


class RenderableMesh : public Renderable
{
public:

    RenderableMesh (std::shared_ptr<sf::RenderWindow> window,
                    const RenderUtility& transformUtility,
                    const Mesh& mesh);

    void Draw () override;


private:

    const Mesh& m_Mesh;

    sf::VertexArray m_VertexArray;


};


#endif //FLUIDSIM_RENDERABLEMESH_HPP
