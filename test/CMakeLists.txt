set(TESTNAME testDU)
add_executable(
    ${TESTNAME}
    ../lib/DUEdge.cc
    ../lib/DUNode.cc
    Main.cc
)

target_include_directories(${TESTNAME} PRIVATE
    ${CMAKE_INSTALL_PREFIX}/include/slim
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
)

add_library(slim SHARED IMPORTED)
set_target_properties(slim PROPERTIES IMPORTED_LOCATION "/usr/local/lib/libslim.so")

target_link_libraries(${TESTNAME} PRIVATE slim LLVM)
