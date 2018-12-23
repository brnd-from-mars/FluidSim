//
// Created by Brendan Berg on 19.12.18.
//

#include <Graphics/RenderableMesh.hpp>


RenderableMesh::RenderableMesh (std::shared_ptr<sf::RenderWindow> window,
                                const RenderUtility& transformUtility,
                                const Mesh& mesh)
: Renderable(std::move(window), transformUtility), m_Mesh(mesh),
  m_VertexArray(sf::Points)
{ }


void RenderableMesh::Draw ()
{
    auto cells = m_Mesh.GetMeshCells();

    m_VertexArray.clear();

    for (auto& column : cells)
    {
        for (auto& cell : column)
        {
            sf::Color color;

            switch (cell.GetType())
            {
                case MeshCell::Type::normal:
                    color = sf::Color::White;
                    break;
                case MeshCell::Type::inactive:
                    color = sf::Color::Magenta;
                    break;
                case MeshCell::Type::inlet:
                    color = sf::Color::Blue;
                    break;
                case MeshCell::Type::outlet:
                    color = sf::Color::Red;
                    break;
                case MeshCell::Type::wall:
                    color = sf::Color::Yellow;
                    break;
            }

            auto pos = m_TransformUtility.TransformPoint(cell.GetCoordinate());

            m_VertexArray.append(sf::Vertex(pos, color));
        }
    }

    m_Window->draw(m_VertexArray);
}
