#include "DUEdge.hh"
#include "DUNode.hh"
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
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
                vector<Edge> &edges) {
    cin >> V;
    nodes.resize(V + 1);
    for (uint32_t i = 1; i <= V; i++) {
        nodes[i] = Node(i);
    }
    cin >> E;
    edges.resize(E + 1);
    for (uint32_t i = 0; i < E; i++) {
        EdgeId e;
        NodeId n1, n2;
        cin >> e >> n1 >> n2;
        edges[e] = Edge(e, n1, n2);
        Result<void> r;
        r = nodes[n1].addOutEdge(e);
        if (!r.success) {
            cerr << "Error adding Outgoing Edge " << e << " to Node " << n1
                 << "\n";
            exit(EXIT_FAILURE);
        }
        r = nodes[n2].addInEdge(e);
        if (!r.success) {
            cerr << "Error adding Incoming Edge " << e << " to Node " << n2
                 << "\n";
            exit(EXIT_FAILURE);
        }
    }
    uint32_t C;
    cin >> C;
    for (uint32_t i = 0; i < C; i++) {
        NodeId n;
        EdgeId e1, e2;
        cin >> n >> e1 >> e2;
        nodes[n].addConnection(e1, e2);
    }
}

void printGraph(const uint32_t &V, const uint32_t &E, const vector<Node> &nodes,
                const vector<Edge> &edges, std::string filename = "graph.gv") {
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

int main() {
    // Taking input
    uint32_t V, E;
    vector<Node> nodes;
    vector<Edge> edges;
    inputGraph(V, E, nodes, edges);
    // Input end

    // Printing the graph
    printGraph(V, E, nodes, edges);
    // Printing end

    for (uint32_t i = 1; i <= E; i++) {
        Edge edge = edges[i];
        Result<NodeId> destId = edge.getDest();
        if (!destId.success) {
            cerr << "Error getting destination for Edge " << edge.getId()
                 << "\n";
            exit(EXIT_FAILURE);
        }
        Node dest = nodes[destId.value];
        Result<set<EdgeId>> connections = dest.nextEdges(edge.getId());
        if (!connections.success) {
            cerr << "Error getting connections for Edge " << edge.getId()
                 << " on Node " << dest.getId() << "\n";
            exit(EXIT_FAILURE);
        }
        for (EdgeId next : connections.value) {
            cout << edge.getId() << " " << next << "\n";
        }
    }

    return EXIT_SUCCESS;
}
