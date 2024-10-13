#include "DUNode.hh"
#include "result.hh"
#include "types.hh"
#include <map>
#include <set>

Node::Node() { this->id = 0; }

Node::Node(NodeId id) { this->id = id; }

NodeId Node::getId() { return this->id; }

Result<void> Node::addInEdge(EdgeId in) {
    if (inEdges.find(in) != inEdges.end()) {
        return {false};
    }
    inEdges.insert(in);
    edgeConnection[in] = {};
    return {true};
}

Result<void> Node::addOutEdge(EdgeId out) {
    if (outEdges.find(out) != outEdges.end()) {
        return {false};
    }
    outEdges.insert(out);
    return {true};
}

Result<void> Node::addConnection(EdgeId in, EdgeId out) {
    if (inEdges.find(in) == inEdges.end()) {
        return {false};
    }
    if (outEdges.find(out) == outEdges.end()) {
        return {false};
    }
    edgeConnection[in].insert(out);
    return {true};
}

Result<void> Node::addConnection(EdgeId in, std::set<EdgeId> out) {
    if (inEdges.find(in) == inEdges.end()) {
        return {false};
    }
    for (EdgeId e : out) {
        if (outEdges.find(e) == outEdges.end()) {
            return {false};
        }
    }
    edgeConnection[in].insert(out.begin(), out.end());
    return {true};
}

Result<std::set<EdgeId>> Node::nextEdges(EdgeId in) {
    if (inEdges.find(in) == inEdges.end()) {
        return {false, {}};
    }
    if (edgeConnection.find(in) == edgeConnection.end()) {
        return {false, {}};
    }
    return {true, edgeConnection[in]};
}

Result<std::set<EdgeId>> Node::getInEdges() { return {true, inEdges}; }
Result<std::set<EdgeId>> Node::getOutEdges() { return {true, outEdges}; }
