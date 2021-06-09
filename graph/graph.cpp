#include "graph.h"
#include <vector>
#include <unordered_set>
#include <queue>

GraphNode::GraphNode() {
  val = 0;
  neighbors = std::vector<GraphNode*>();
}

GraphNode::GraphNode(int val) {
  this->val = val;
  neighbors = std::vector<GraphNode*>();
}

GraphNode::GraphNode(int val, std::vector<GraphNode*> neighbors) {
  this->val = val;
  this->neighbors = neighbors;
}

GraphNode* GraphNode::addNeighbor(GraphNode* neighbor) {
  this->neighbors.push_back(neighbor);
  return this;
}

std::vector<GraphNode*> getGraphNodesList(GraphNode* node);

void assertEquals(GraphNode* actual, GraphNode* expected, std::string file, int line) {
  if (actual == nullptr && expected == nullptr) {
    return;
  }

  if (actual == nullptr || expected == nullptr) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
    return;
  }

  std::vector<GraphNode*> actual_graph_nodes_list = getGraphNodesList(actual);
  std::vector<GraphNode*> expected_graph_nodes_list = getGraphNodesList(expected);

  if (actual_graph_nodes_list.size() != expected_graph_nodes_list.size()) {
    std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
              << " in " << file << std::endl;
    return;
  }

  int n = actual_graph_nodes_list.size();
  for (int i = 0; i < n; ++i) {
    if (actual_graph_nodes_list[i]->val != expected_graph_nodes_list[i]->val) {
      std::cerr << "Failed " << __FUNCTION__ << " for test: line " << line
                << " in " << file << std::endl;
      return;
    }
  }
}

std::vector<GraphNode*> getGraphNodesList(GraphNode* node) {
  std::vector<GraphNode*> node_list;
  std::unordered_set<GraphNode*> seen_nodes;

  std::queue<GraphNode*> nodes;
  nodes.push(node);
  while (!nodes.empty()) {
    GraphNode* current_node = nodes.front();
    nodes.pop();

    node_list.push_back(current_node);

    for (GraphNode* neighbor: current_node->neighbors) {
      if (seen_nodes.find(neighbor) == seen_nodes.end()) {
        seen_nodes.insert(neighbor);
        nodes.push(neighbor);
      }
    }
  }

  return node_list;
}
