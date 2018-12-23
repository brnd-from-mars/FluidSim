add_library(Mesh
        Mesh.cpp
        MeshCell.cpp)

target_include_directories(Mesh
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Mesh Utility Geometry)
