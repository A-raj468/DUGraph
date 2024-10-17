#include "DUEdge.hh"
#include "DUNode.hh"

#include <cstdint>
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

#ifndef NDEBUG
#define DEBUG(x)                                                               \
    do {                                                                       \
        x;                                                                     \
    } while (0)
#else
#define DEBUG(x)
#endif

using namespace std;

void inputGraph(uint32_t &V, uint32_t &E, vector<Node> &nodes,
                vector<Edge> &edges, const string &inputContent) {

    istringstream inputStream(inputContent);

    inputStream >> V;
    nodes.resize(V + 1);
    for (uint32_t i = 1; i <= V; i++) {
        nodes[i] = Node(i);
    }
    inputStream >> E;
    edges.resize(E + 1);
    for (uint32_t i = 0; i < E; i++) {
        EdgeId e;
        NodeId n1, n2;
        inputStream >> e >> n1 >> n2;
        edges[e] = Edge(e, n1, n2);
        Result<void> r;
        r = nodes[n1].addOutEdge(e);
        ASSERT_TRUE(r.success)
            << "Error adding Outgoing Edge " << e << " to Node " << n1 << "\n";
        r = nodes[n2].addInEdge(e);
        ASSERT_TRUE(r.success)
            << "Error adding Incoming Edge " << e << " to Node " << n2 << "\n";
    }
    uint32_t C;
    inputStream >> C;
    for (uint32_t i = 0; i < C; i++) {
        NodeId n;
        EdgeId e1, e2;
        inputStream >> n >> e1 >> e2;
        nodes[n].addConnection(e1, e2);
    }
}

void printGraph(const uint32_t &V, const uint32_t &E, const vector<Node> &nodes,
                const vector<Edge> &edges, string filename = "graph.gv") {
    DEBUG(
        ofstream out(filename);
        out << "digraph G {\n"; for (uint32_t i = 1; i <= V; i++) {
            Node n = nodes[i];
            out << "    " << n.getId() << ";\n";
        } for (uint32_t i = 1; i <= E; i++) {
            Edge e = edges[i];
            out << "    " << e.getSrc().value << " -> " << e.getDest().value
                << " [label=\"e" << e.getId() << "\"];\n";
        } out << "}\n";);
}

// Helper function to read file content
string readFile(const string &file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + file_path);
    }
    return string((istreambuf_iterator<char>(file)),
                  istreambuf_iterator<char>());
}

void runTestCase(const string &inputFilePath,
                 const string &expectedOutputFilePath) {
    string inputContent = readFile(inputFilePath);
    string expectedOutputContent = readFile(expectedOutputFilePath);

    // Taking input
    uint32_t V, E;
    vector<Node> nodes;
    vector<Edge> edges;
    inputGraph(V, E, nodes, edges, inputContent);
    // Input end

    // Printing the graph
    printGraph(V, E, nodes, edges);
    // Printing end

    std::ostringstream resultStream;

    for (uint32_t i = 1; i <= E; i++) {
        Edge edge = edges[i];
        Result<NodeId> destId = edge.getDest();
        ASSERT_TRUE(destId.success)
            << "Error getting destination for Edge " << edge.getId() << "\n";
        Node dest = nodes[destId.value];
        Result<set<EdgeId>> connections = dest.nextEdges(edge.getId());
        ASSERT_TRUE(connections.success)
            << "Error getting connections for Edge " << edge.getId()
            << " on Node " << dest.getId() << "\n";
        for (EdgeId next : connections.value) {
            resultStream << edge.getId() << " " << next << "\n";
        }
    }

    ASSERT_EQ(resultStream.str(), expectedOutputContent);
}

TEST(SimpleAddTest, TestCase1) {
    runTestCase(string(TEST_INPUT_DIR) + "/testcases/inputs/test1.txt",
                string(TEST_INPUT_DIR) + "/testcases/outputs/test1.txt");
}

TEST(SimpleAddTest, TestCase2) {
    runTestCase(string(TEST_INPUT_DIR) + "/testcases/inputs/test2.txt",
                string(TEST_INPUT_DIR) + "/testcases/outputs/test2.txt");
}
