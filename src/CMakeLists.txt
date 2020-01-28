add_library (Matchmake matchmake.cpp matchmake.h)
add_library (Trimmer trimmer.cpp trimmer.h)
add_library (CompareTeams compare_teams.cpp compare_teams.h)


add_executable (matchmake main.cpp)


target_link_libraries (matchmake Matchmake Trimmer CompareTeams)

install(TARGETS matchmake RUNTIME DESTINATION bin DESTINATION ${LIBEXEC_INSTALL_DIR})
