//
// Created by Brendan Berg on 19.12.18.
//

#include <Graphics/RenderableGeometry.hpp>
#include <Graphics/RenderableMesh.hpp>

#include <Graphics/RenderController.hpp>


RenderController::RenderController (unsigned int windowWidth,
                                    unsigned int windowHeight,
                                    const std::string& windowTitle,
                                    const Boundary<double>& contentBoundary)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;

    m_Window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(windowWidth, windowHeight),
        windowTitle,
        sf::Style::Default,
        settings);

    m_TransformUtility = RenderUtility(m_Window->getSize(), contentBoundary);
}


void RenderController::CreateGeometryRenderer (const GeometrySet& geometry)
{
    std::unique_ptr<Renderable> ptr =
        std::make_unique<RenderableGeometry>(m_Window,
                                             m_TransformUtility,
                                             geometry);
    m_Renderables.push_back(std::move(ptr));
}


void RenderController::CreateMeshRenderer (const Mesh& mesh)
{
    std::unique_ptr<Renderable> ptr =
        std::make_unique<RenderableMesh>(m_Window,
                                         m_TransformUtility,
                                         mesh);
    m_Renderables.push_back(std::move(ptr));
}


bool RenderController::IsRunning ()
{
    return m_Window->isOpen();
}


void RenderController::Draw ()
{
    auto event = sf::Event();
    while (m_Window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                m_Window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape)
                {
                    m_Window->close();
                }
                break;
            default:
                break;
        }
    }

    for (auto& renderable : m_Renderables)
    {
        renderable->Draw();
    }

    m_Window->setFramerateLimit(30);
    m_Window->display();
}
