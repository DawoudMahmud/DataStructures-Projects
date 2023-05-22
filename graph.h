#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>
#include "node.h"

class Graph 
{
	public:
		// DO NOT MODIFY MEMBERS BELOW THIS LINE
        int get_num_nodes(); 						// get number of nodes
        int get_num_edges(); 						// get number of edges
        std::vector<Node> get_neighbors(Node u); 	// return neighbors of u 
        std::map<int, Node> get_id_to_node_map(); 	// allows lookup of nodes from ids
		// DO NOT MODIFY MEMBERS ABOVE THIS LINE
    
    Graph();
    Graph(int NodeCount);
    void setNumNodes(int n);
    void setNumEdges(int e);
    std::pair<Node,int> maxDistance(Node inNode);
    bool is_neighbor(Node u, Node v);
    std::vector<std::vector<Node>> neighbors;
    std::vector<Node> nodeIDs;
    
    private:
        int numNodes;
        int numEdges;
    
    
};

#endif
