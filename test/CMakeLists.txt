find_package(Qt5Test REQUIRED)

include_directories (${TEST_SOURCE_DIR}
                     )

add_executable (bva boundary_value_test.cpp)

target_link_libraries (bva
                       Qt5::Test
                       Matchmake
                       )

add_test (NAME BVTest COMMAND bva)