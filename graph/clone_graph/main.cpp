#include "../../test.h"
#include "../graph.h"
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Given a reference of a node in a connected undirected
 * graph, return a deep copy of the graph.
 */
GraphNode* cloneGraph(GraphNode* node) {
  if (node == nullptr) {
    return nullptr;
  }

  unordered_map<GraphNode*, GraphNode*> seen;
  seen[node] = new GraphNode(node->val);;

  queue<GraphNode*> nodes;
  nodes.push(node);

  while(!nodes.empty()) {
    GraphNode* current_node = nodes.front();
    nodes.pop();

    for (GraphNode* neighbor: current_node->neighbors) {
      if (seen.find(neighbor) == seen.end()) {
        seen[neighbor] = new GraphNode(neighbor->val);;
        nodes.push(neighbor);
      }

      seen[current_node]->neighbors.push_back(seen[neighbor]);
    }
  }

  return seen[node];
}

int main() { 
  GraphNode* node_1 = new GraphNode(1);
  GraphNode* node_2 = new GraphNode(2, (vector<GraphNode*>{node_1}));
  GraphNode* node_3 = new GraphNode(3, (vector<GraphNode*>{node_1, node_2}));
  GraphNode* node_4 = new GraphNode(4, (vector<GraphNode*>{node_1, node_2, node_3}));
  GraphNode* node_5 = new GraphNode(5, (vector<GraphNode*>{node_1, node_2, node_3, node_4}));

  ASSERT_EQUALS(cloneGraph(nullptr), nullptr);
  ASSERT_EQUALS(cloneGraph(node_1), node_1);
  ASSERT_EQUALS(cloneGraph(node_2), node_2);
  ASSERT_EQUALS(cloneGraph(node_3), node_3);
  ASSERT_EQUALS(cloneGraph(node_4), node_4);
  ASSERT_EQUALS(cloneGraph(node_5), node_5);

  GraphNode* two_nodes_1 = new GraphNode(1);
  GraphNode* two_nodes_2 = new GraphNode(2, (vector<GraphNode*>{two_nodes_1}));
  two_nodes_1->addNeighbor(two_nodes_2);

  ASSERT_EQUALS(cloneGraph(two_nodes_1), two_nodes_1);

  GraphNode* four_nodes_1 = new GraphNode(1);
  GraphNode* four_nodes_2 = new GraphNode(2);
  GraphNode* four_nodes_3 = new GraphNode(3);
  GraphNode* four_nodes_4 = new GraphNode(4);
  four_nodes_1->addNeighbor(four_nodes_2)->addNeighbor(four_nodes_4);
  four_nodes_2->addNeighbor(four_nodes_1)->addNeighbor(four_nodes_3);
  four_nodes_3->addNeighbor(four_nodes_2)->addNeighbor(four_nodes_4);
  four_nodes_4->addNeighbor(four_nodes_1)->addNeighbor(four_nodes_3);

  ASSERT_EQUALS(cloneGraph(four_nodes_1), four_nodes_1);
}
