#include "graph.h"
#include "node.h"
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <iostream>
#include <ctime>
#include <time.h>

std::pair<Node, int> search(Graph g, Node start) {
    int totalNodes = g.get_num_nodes();
    std::queue<int> Q;
    bool* visited = new bool[totalNodes];
    int* dist= new int[totalNodes];
    int max_distance = 0;
    Node max_node(start);
    for (int i = 0; i < totalNodes; ++i) {
        visited[i] = false;
        dist[i] = 0;
    }
    visited[start.id - 1] = true;
    Q.push(start.id);

    while (Q.empty() == false) {
        Node n(Q.front());
        Q.pop();
        std::vector<Node> allNeighbors = g.get_neighbors(n);
        for (int i = 0; i < allNeighbors.size(); ++i)
        {
            if (visited[allNeighbors[i].id - 1] == false)
            {
                Q.push(allNeighbors[i].id);
                visited[allNeighbors[i].id - 1] = true;
                dist[allNeighbors[i].id - 1] = dist[n.id - 1] + 1;
            }
        }
    }
    
    for (int i = 0; i < totalNodes; ++i)
    {
        if (dist[i] > max_distance)
        {
            max_distance = dist[i];
            max_node = Node(i + 1);
        }
    }
    std::pair<Node, int> toReturn = std::make_pair(max_node, max_distance);
    return toReturn;
}

int get_diameter(Graph g) {
    int diameter = 0;
    int totalNodes = g.get_num_nodes();
    if (totalNodes == 0)
        return 0;
    else if(totalNodes == 1)
        return 0;
    int maxDis = 0;
    srand (time(NULL));
    Node fNode(1);
    std::pair<Node, int> farthest = std::make_pair(fNode, maxDis);
    do
    {
        diameter = farthest.second;
        farthest = search(g, farthest.first);
    }
    while (farthest.second > diameter);
    
    return diameter;
}


float get_clustering_coefficient(Graph g) {
    int triangles = 0;
    int twoPaths = 0;
    int degeneracy = 0;
    int totalNodes = g.get_num_nodes();
    for (int i = 0; i < totalNodes; ++i) {
        Node n(i+1);
        int degr = g.get_neighbors(n).size();
        twoPaths += degr * (degr - 1) / 2;
    }
    std::stack<int> iStack;
    std::unordered_set<int> iSet;
    std::map<int, std::unordered_set<int>> iMap;
    int deg[totalNodes];
    std::vector<int> N[totalNodes];
    for (int i = 0; i < totalNodes; ++i) {
        Node n(i+1);
        int degr = g.get_neighbors(n).size();
        iMap[degr].insert(i+1);
        deg[i] = degr;
    }
    for (int j = 0; j < totalNodes; ++j) {
        int sDegr = -1;
        for (auto i = iMap.begin(); i != iMap.end(); ++i) {
            if (i->second.empty() == false) {
                sDegr = i->first;
                break;
            }
        }
        std::unordered_set<int> nodes = iMap[sDegr];
        if (sDegr > degeneracy)
            degeneracy = sDegr;
        //degeneracy = max(degeneracy, sDegr);
        int v = *nodes.begin();
        iStack.push(v);
        iSet.insert(v);
        iMap[sDegr].erase(v);
        std::vector<Node> neighbors = g.get_neighbors(Node(v));
        for (int k = 0; k < neighbors.size(); ++k) {
            Node nb = neighbors[k];
            int nid = nb.id;
            if (iSet.find(nid) == iSet.end()) {
                int curDeg = deg[nid - 1]--;
                iMap[curDeg].erase(nid);
                iMap[curDeg - 1].insert(nid);
                N[v - 1].push_back(nid);
            }
        }
    }
    while (iStack.empty() == false) {
        int v = iStack.top();
        std::vector<int> n_v = N[v - 1];
        int size = n_v.size();
        for (int p = 0; p < size - 1; ++p) {
            for (int q = p + 1; q < size; ++q) {
                if (g.is_neighbor(Node(n_v[p]), Node(n_v[q])))
                    ++triangles;
            }
        }
        iStack.pop();
    }
    float to_return = 3.0 * triangles / twoPaths;
    return to_return;
}

std::map<int, int> get_degree_distribution(Graph g) {
    int num_nodes = g.get_num_nodes();
    std::map<int, int> to_return;

    for (int i = 0; i < num_nodes; ++i) {
        Node n(i+1);
        int deg = g.get_neighbors(n).size();
        to_return[deg] = to_return[deg] + 1;
    }
    return to_return;
}


//int main()
//{
//    std::cout << "running\n";
//}
