#include "DUEdge.hh"

Edge::Edge() {
    this->id = 0;
    this->src = 0;
    this->dest = 0;
}

Edge::Edge(EdgeId id, NodeId src, NodeId dest) {
    this->id = id;
    this->src = src;
    this->dest = dest;
}

EdgeId Edge::getId() { return this->id; }
Result<NodeId> Edge::getSrc() { return {true, src}; }
Result<NodeId> Edge::getDest() { return {true, dest}; }
