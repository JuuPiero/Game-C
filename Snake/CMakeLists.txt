project(Snake)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../PieroEngine/include)

target_link_libraries(${PROJECT_NAME} PieroEngine)