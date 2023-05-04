#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    // initialize the distance matrix
    cout << "Enter the edges and their weights: " << endl;
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = w;
    }
    for(int i=0; i<n; i++) {
        dist[i][i] = 0;
    }

    // apply Floyd Warshall Algorithm
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // print the result
    cout << "The all pair shortest path matrix is: " << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
