cmake_minimum_required(VERSION 3.10)
project(GeoQuiz)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/includes)

file(GLOB SOURCES
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
