add_library(Graphics
        RenderController.cpp
        RenderUtility.cpp
        Renderable.cpp
        RenderableGeometry.cpp
        RenderableMesh.cpp)

target_include_directories(Graphics
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(Graphics sfml-graphics Geometry Mesh)
