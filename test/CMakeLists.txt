find_package(Qt5Test REQUIRED)

include_directories (
                    ${CMAKE_SOURCE_DIR}
                    )
add_executable (bva boundary_value_test.cpp)

set_property(TARGET bva PROPERTY AUTOMOC ON)
target_link_libraries (bva
                       Qt5::Test
                       Matchmake
                       )

install(TARGETS bva DESTINATION ${LIBEXEC_INSTALL_DIR})

add_test (NAME BVTest COMMAND bva --exe ${LIBEXEC_INSTALL_DIR}/bva)