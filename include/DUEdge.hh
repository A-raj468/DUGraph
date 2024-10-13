#pragma once

#include "result.hh"
#include "types.hh"

class Edge {
  private:
    EdgeId id;
    NodeId src;
    NodeId dest;

  public:
    Edge();
    Edge(EdgeId id, NodeId src, NodeId dest);
    EdgeId getId();
    Result<NodeId> getSrc();
    Result<NodeId> getDest();
};
