# 收集源文件
file(GLOB_RECURSE SOURCES 
    "*.cpp"
)

# 创建库
add_library(planet_evolution STATIC ${SOURCES})

# 设置包含目录
target_include_directories(planet_evolution
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# 设置编译选项
target_compile_options(planet_evolution
    PRIVATE
    $<$<CONFIG:Debug>:-g -Wall -Wextra -Wpedantic>
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
) 