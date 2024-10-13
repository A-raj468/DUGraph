add_llvm_pass_plugin(libduedges
    DUEdge.cc
    DUNode.cc
)

target_include_directories(libduedges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../include")

