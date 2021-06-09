#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class GraphNode {
public:
  int val;
  std::vector<GraphNode*> neighbors;

  GraphNode();
  GraphNode(int val);
  GraphNode(int val, std::vector<GraphNode*> neighbors);

  GraphNode* addNeighbor(GraphNode* neighbor);
};

void assertEquals(GraphNode* actual, GraphNode* expected, std::string file, int line);

#endif
