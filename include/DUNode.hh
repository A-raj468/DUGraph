#pragma once

#include "result.hh"
#include "types.hh"
#include <map>
#include <set>

class Node {
  private:
    NodeId id;
    std::set<EdgeId> inEdges;
    std::set<EdgeId> outEdges;
    std::map<EdgeId, std::set<EdgeId>> edgeConnection;

  public:
    Node();
    Node(NodeId id);
    NodeId getId();
    Result<void> addInEdge(EdgeId id);
    Result<void> addOutEdge(EdgeId id);
    Result<void> addConnection(EdgeId in, EdgeId out);
    Result<void> addConnection(EdgeId in, std::set<EdgeId> out);
    Result<std::set<EdgeId>> nextEdges(EdgeId id);

    Result<std::set<EdgeId>> getInEdges();
    Result<std::set<EdgeId>> getOutEdges();
};
