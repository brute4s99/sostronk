add_library (Matchmake matchmake.cpp matchmake.h)
add_library (Trimmer trimmer.cpp trimmer.h)
add_executable (matchmake main.cpp)
target_link_libraries (matchmake Matchmake Trimmer)

install(TARGETS matchmake DESTINATION ${LIBEXEC_INSTALL_DIR})
