#include "graph.h"
#include "node.h"
#include <iostream>
#include <queue>
#include <algorithm>


Graph::Graph()
{
    numNodes = 0;
    numEdges = 0;
}

Graph::Graph(int n)
{
    numNodes = n;
}

void Graph:: setNumNodes(int n)
{
    numNodes = n;
}

void Graph:: setNumEdges(int e)
{
    numEdges = e;
}

int Graph::get_num_nodes() {
	return numNodes; 
}

int Graph::get_num_edges() {
	return numEdges;
}

std::vector<Node> Graph::get_neighbors(Node u)
{
    return neighbors[u.id-1];
}

std::map<int, Node>Graph::get_id_to_node_map(){
    std::map<int, Node> to_return;
    for (int i = 0; i < get_num_nodes(); ++i) {
        to_return[i+1] = nodeIDs[i];
    }
    return to_return;
}

Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v){
    Graph toReturn = Graph(num_nodes);
    toReturn.setNumEdges(u.size());
        for (int i = 0; i < num_nodes; ++i)
        {
            Node* newNode = new Node(i+1);
            toReturn.nodeIDs.push_back(*newNode);
        }
        for (int i = 0; i < num_nodes; ++i)
        {
            std::vector<Node> to_fill;
            toReturn.neighbors.push_back(to_fill);
        }
        for (int i = 0; i < toReturn.get_num_edges(); i++)
        {
            toReturn.neighbors[u[i]-1].push_back(toReturn.nodeIDs[v[i]-1]);
            toReturn.neighbors[v[i]-1].push_back(toReturn.nodeIDs[u[i]-1]);
        }

    
    return toReturn;
}

std::pair<Node,int> Graph::maxDistance(Node inNode)
{
    int far = 0;
    Node furthest_node = inNode;
    std::vector<bool> checked(get_num_nodes(), false);
    std::vector<int> distance(get_num_nodes(), 0);
    std::queue<Node> distanceQ;
    distanceQ.push(inNode.id);
    checked[inNode.id-1] = true;
    while (distanceQ.empty() == false)
    {
            inNode = distanceQ.front();
            distanceQ.pop();
        std::vector<Node> nei = get_neighbors(inNode);
        for (int i = 0; i < nei.size(); ++i)
        {
                if (!checked[nei[i].id - 1]) {
                    checked[nei[i].id - 1] = true;
                    distance[nei[i].id - 1] = distance[nei[i].id-1] + 1;
                    if (distance[nei[i].id-1] > far) {
                        furthest_node = nei[i];
                        far = distance[nei[i].id-1];
                    }
                    distanceQ.push(nei[i]);
                }
            }
    }
        return std::pair<Node, int>(furthest_node, far);
}

bool Graph::is_neighbor(Node u, Node v)
{
    std::vector<Node> to_compare = neighbors.at(u.id - 1);
    for (int i = 0; i < to_compare.size(); ++i)
    {
        if (to_compare.at(i).id == v.id)
        {
            return true;
        }
    }
    return false;
}
//int main()
//{
//    std::cout << "running\n";
//}
