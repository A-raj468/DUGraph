enable_testing()

find_package(GTest REQUIRED)

set(TESTNAME testDU)

add_executable(
    ${TESTNAME}
    Main.cc
)

target_include_directories(${TESTNAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(${TESTNAME} PRIVATE
    GTest::GTest GTest::Main
    libduedges
)

target_compile_definitions(${TESTNAME} PRIVATE TEST_INPUT_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_test(NAME DUTest COMMAND ${TESTNAME})
