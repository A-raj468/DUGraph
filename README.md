# CosDU Graph Data Structure

This project implements a directed graph data structure with specific restrictions on edge connections.

## Overview

The **CosDU Graph** is designed to model a graph with controlled connections between edges at each node.
The graph consists of **Nodes** and **Edges**, with each node restricting which incoming edges can connect to which outgoing edges.

## Data Structure

The graph is represented by two primary components:

1. Edge
   - Each edge has a unique `EdgeId`.
   - An edge connects a source node (`src NodeId`) to a destination node (`dest NodeId`).
2. Node
   - Each node has a unique `NodeId`.
   - A node maintains:
     - A set of all incoming edges.
     - A set of all outgoing edges.
     - A mapping that specifies which incoming edges can connect to which outgoing edges.

The overall graph consists of:

- A vector of all Edges.
- A vector of all Nodes.

## Dependencies

This project uses the following external libraries and tools:

1. **GoogleTest (GTest)** for unit testing.
2. **Graphviz** for visualizing the graph structure in DOT format.

### Installing Dependencies

Make sure to install the required dependencies on your system:

```bash
# On Ubuntu/Debian:
sudo apt update
sudo apt install -y cmake g++ graphviz

# for gtest, follow the official installation guide
sudo apt install -y libgtest-dev
cd /use/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp ./lib/libgtest*.a /use/local/lib
```

## Unit Tests

The project includes unit tests using **GoogleTest (GTest)** that:

- Automatically compare the results of graph computations with expected outputs.
- Ensure the correctness of the graph structure by verifying the results against predefined test cases.

### Testing Behavior

- **Debug Mode**: When the build type is set to `Debug` (default), additional diagnostic information such as the graph structure in **DOT format** is outputted to a file named `graph.gv` in the `build/test` directory for visual inspection. This file can be used to manually verify the graph’s state by loading it into a graph visualization tool (e.g., Graphviz).
- **Test Cases**: Each test case consists of:
  - An **input file** specifying the graph's input data.
  - An **output file** containing the correct results for validation.

The tests automatically compare the generated output of the program with the expected results to ensure correctness.

### Running the Tests

Tests are executed using `ctest` and automatically check for correctness by comparing the output with the expected results. In debug mode, a file `graph.gv` is generated containing the graph structure in DOT format, which can be inspected using graph visualization tools.

To run the tests, use the following commands:

```bash
# Build the project in Debug mode (default)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Run tests
ctest --test-dir=build/test --output-on-failure
```

To view the graph output in `graph.gv`, use a tool like Graphviz to visualize the graph:

```bash
cd build/test
dot -Tpng graph.gv -o graph.png
```
