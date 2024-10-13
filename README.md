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

## Unit Tests

The project includes unit tests that:

- Print the graph structure in **DOT format** for visual inspection.
- Output all the edge connections for each node in the graph, showing how incoming edges can connect to outgoing edges.
