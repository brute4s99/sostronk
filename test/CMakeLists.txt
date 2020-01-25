find_package(Qt5Test REQUIRED)

include_directories (
                    ${CMAKE_SOURCE_DIR}
                    )

set( TEST_LIBRARIES
     Matchmake
     Trimmer
     Qt5::Test
     ${QT_QTTEST_LIBRARY}
     ${QT_LIBRARIES}
    )

macro(add_a_test name cpp)
add_executable( ${cpp} ${cpp}.cpp )
target_link_libraries( ${cpp} ${TEST_LIBRARIES} )
add_test( NAME ${name} COMMAND ${cpp} )
endmacro()

add_a_test(TrimmerTest trimmer_test)
#add_a_test(MatchMakeTest matchmake_test)
#add_a_test(CompareTeamsTest compare_teams_test)
