cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
project(GameEngine)

add_subdirectory(Dependencies)
add_subdirectory(Game)
add_subdirectory(PieroEngine)


add_subdirectory(Test)

add_subdirectory(Snake)
add_subdirectory(FlappyBird)



# file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp")

# add_executable(${PROJECT_NAME} ${SOURCES})

# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/SDL2/include)
# target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/SDL2/lib)

# target_link_libraries(${PROJECT_NAME} SDL2 SDL2main SDL2_image)