add_library (Matchmake main.cpp main.h)
add_executable (matchmake main.cpp)
target_link_libraries (matchmake Matchmake)

install(TARGETS matchmake DESTINATION ${LIBEXEC_INSTALL_DIR})
