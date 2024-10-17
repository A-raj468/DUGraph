set(TESTNAME testDU)

add_executable(
    ${TESTNAME}
    Main.cc
)

target_include_directories(${TESTNAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(${TESTNAME} PRIVATE
    libduedges
)
