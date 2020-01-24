find_package(Qt5Test REQUIRED)

include_directories (
                    ${CMAKE_SOURCE_DIR}
                    )

set( TEST_LIBRARIES Matchmake Qt5::Test ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES} )

add_executable( bv_test boundary_value_test.cpp )
target_link_libraries( bv_test ${TEST_LIBRARIES} )
add_test( NAME BoundaryValueTest COMMAND bv_test )