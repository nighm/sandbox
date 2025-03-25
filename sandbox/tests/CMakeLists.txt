# 查找GTest包
find_package(GTest REQUIRED)

# 收集测试源文件
file(GLOB_RECURSE TEST_SOURCES 
    "*.cpp"
)

# 创建测试可执行文件
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

# 链接测试库
target_link_libraries(${PROJECT_NAME}_tests
    PRIVATE
    GTest::GTest
    GTest::Main
    ${PROJECT_NAME}
)

# 添加测试
add_test(NAME ${PROJECT_NAME}_tests COMMAND ${PROJECT_NAME}_tests)

# 设置包含目录
target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
) 