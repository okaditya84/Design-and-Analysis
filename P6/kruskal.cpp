#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to compare edges by their weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent of a subset using path compression technique
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to do union of two subsets using rank       
void unionSubsets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the Minimum Spanning Tree of the graph using Kruskal's algorithm
vector<Edge> kruskalMST(int V, vector<Edge> edges) {
    vector<Edge> result;
    Subset subsets[V];
    int e = 0;

    // Sort all the edges in increasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize subsets for union-find
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Process all the edges in sorted order
    for (int i = 0; i < edges.size(); i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        // If including this edge does not cause a cycle, include it in result and increment the index of result
        if (x != y) {
            result.push_back(edges[i]);
            unionSubsets(subsets, x, y);
            e++;
        }

        // If we have included V-1 edges, we have found the MST
        if (e == V - 1)
            break;
    }

    return result;
}

// Function to print the edges of the MST
void printMST(vector<Edge> edges) {
    int total_weight = 0;
    cout << "Edges of the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].src << " -- " << edges[i].dest << "  (weight: " << edges[i].weight << ")" << endl;
        total_weight += edges[i].weight;
    }
    cout << "Total weight of the MST: " << total_weight << endl;
}

// Driver code
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Enter the source vertex, destination vertex, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        Edge e;
        cin >> e.src >> e.dest >> e.weight;
        edges.push_back(e);
    }

    vector<Edge> mst = kruskalMST(V, edges);
    printMST(mst);

    return 0;
}

