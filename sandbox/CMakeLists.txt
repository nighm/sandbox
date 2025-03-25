cmake_minimum_required(VERSION 3.22.1)
project(SandboxSimulator VERSION 0.1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置编译选项
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# 查找必要的包
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
find_package(Box2D REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# 设置包含目录
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${SFML_INCLUDE_DIR}
    ${BOX2D_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
)

# 收集源文件
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/core/*.cpp"
    "src/physics/*.cpp"
    "src/rendering/*.cpp"
    "src/ui/*.cpp"
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接库
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    sfml-system
    sfml-window
    sfml-graphics
    Box2D
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
)

# 安装规则
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# 启用测试
enable_testing()
add_subdirectory(tests)

# 复制资源文件
file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

# 版本信息
configure_file(
    ${PROJECT_SOURCE_DIR}/include/Version.hpp.in
    ${PROJECT_BINARY_DIR}/include/Version.hpp
) 