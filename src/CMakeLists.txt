add_library(libduedges
    DUEdge.cc
    DUNode.cc
)

target_include_directories(libduedges PRIVATE
    "${CMAKE_SOURCE_DIR}/include")

