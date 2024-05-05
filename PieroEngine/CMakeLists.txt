project(PieroEngine)

file(GLOB_RECURSE LIB_SOURCES "src/*.cpp" "src/*/*.cpp")

add_library(${PROJECT_NAME} ${LIB_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/SDL2/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/SDL2/lib)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2main SDL2_image)