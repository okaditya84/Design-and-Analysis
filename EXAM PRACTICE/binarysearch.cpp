#include <stdio.h>

// Define a structure to represent an item
struct Item {
    int value;
    int weight;
};

// Compare function to sort items based on their value-to-weight ratios in descending order
int compare(const void *a, const void *b) {
    double ratio1 = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratio2 = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    return ratio2 - ratio1;
}

// Function to find the maximum value we can obtain by taking fractions of items
double fractional_knapsack(int capacity, struct Item items[], int n) {
    // Sort items based on their value-to-weight ratios in descending order
    qsort(items, n, sizeof(struct Item), compare);
    double max_value = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            return max_value;
        }
        // Take the maximum possible amount of the item with the highest value-to-weight ratio
        int take = (capacity > items[i].weight) ? items[i].weight : capacity;
        // Update capacity and maximum value
        capacity -= take;
        max_value += take * (items[i].value / (double)items[i].weight);
    }
    
    return max_value;
}

int main() {
    int capacity = 50;
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    double max_value = fractional_knapsack(capacity, items, n);
    printf("Maximum value: %0.2f\n", max_value);
    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // number of vertices in the graph

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int start) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\t Distance from Start\n");
    for (int i = 0; i < V; i++) {
        printf("shortest dist from %d\t is %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, 3, 0, 0, 0},
        {5, 0, 2, 6, 0, 0},
        {3, 2, 0, 7, 8, 0},
        {0, 6, 7, 0, 1, 4},
        {0, 0, 8, 1, 0, 3},
        {0, 0, 0, 4, 3, 0}
    };#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int kruskal(int n, int m) {
    int cost = 0;
    for (int i = 0; i < n; i++) parent[i] = i;
    qsort(edges, m, sizeof(Edge), cmp);
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].weight;
        printf("Processing edge (%d, %d) with weight %d\n", u, v, w);
        if (find(u) != find(v)) {
            printf("Merging sets containing %d and %d\n", u, v);
            merge(u, v);
            cost += w;
        } else {
            printf("Skipping edge (%d, %d) because it forms a cycle\n", u, v);
        }
    }
    return cost;
}

int main() {
    int n, m;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &n, &m);
    printf("Read in %d vertices and %d edges\n", n, m);
    printf("Enter the edges in the format 'u v w':\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge){u, v, w};
    }
    int cost = kruskal(n, m);
    printf("Total cost of MST is %d\n", cost);
    return 0;
}








#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int v, parent, rank;
} Node;

Edge edges[MAX_EDGES];
Node nodes[MAX_VERTICES];

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int x) {
    if (nodes[x].parent != x) nodes[x].parent = find(nodes[x].parent);
    return nodes[x].parent;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
     // x has higher rank, so make y a child of x
    if (nodes[x].rank > nodes[y].rank) {
        nodes[y].parent = x;
         // y has higher rank, so make x a child of y
    } else {
        nodes[x].parent = y;
         // if ranks are equal, promote y
        if (nodes[x].rank == nodes[y].rank) nodes[y].rank++;
    }
}

int prim(int n, int m, int start) {
    int total_weight = 0;
    int num_visited = 0;
    //initializing node array
    for (int i = 0; i < n; i++) {
        nodes[i].v = i;
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }
    //this indicated that start is root node as it has no parent
    nodes[start].parent = -1;
    int num visited=1;
    while (num_visited < n) {
        int min_edge_weight = INT_MAX;
        int min_edge_idx = -1;
        for (int i = 0; i < m; i++) {
            int u = edges[i].v, v = edges[i].w;
            if (find(u) != find(v) && edges[i].w < min_edge_weight) {
                min_edge_weight = edges[i].w;
                min_edge_idx = i;
            }
        }
        if (min_edge_idx == -1) {
            printf("Error: graph is not connected\n");
            exit(1);
        }
        int u = edges[min_edge_idx].v, v = edges[min_edge_idx].w;
        merge(u, v);
        total_weight += min_edge_weight;
        nodes[v].parent = u;
        num_visited++;
    }
    return total_weight;
}

   int main() {
    int n, m, start;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &n, &m);
    printf("Read in %d vertices and %d edges\n", n, m);

    printf("Enter the start vertex:\n");
    scanf("%d", &start);

    printf("Enter the edges (v w weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].v, &edges[i].w, &edges[i].weight);
    }

    qsort(edges, m, sizeof(Edge), cmp);

    int total_weight = prim(n, m, start);

    printf("The total weight of the minimum spanning tree is %d\n", total_weight);

    return 0;
}


    

    dijkstra(graph, 0);

    return 0;
}






