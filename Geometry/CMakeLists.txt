add_library(Geometry
        GeometrySet.cpp
        Geometry.cpp
        GeoFileParser.cpp
        GeoPoint.cpp)

target_include_directories(Geometry
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
