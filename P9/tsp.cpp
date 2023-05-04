#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5;
int final_path[SIZE + 1];
bool visited[SIZE];
int final_res = INT_MAX;

void copyToFinalPath(int current_path[])
{
    for (int i = 0; i < SIZE; i++)
        final_path[i] = current_path[i];
    final_path[SIZE] = current_path[0];
}

int findFirstMinimum(int graph[SIZE][SIZE], int vertex)
{
    int minCost = INT_MAX;
    for (int j = 0; j < SIZE; j++)
        if (graph[vertex][j] < minCost && vertex != j)
            minCost = graph[vertex][j];
    return minCost;
}
//
int findSecondMinimum(int graph[SIZE][SIZE], int vertex)
{
    int firstMin = INT_MAX, secondMin = INT_MAX;
    for (int j = 0; j < SIZE; j++)
    {
        if (vertex == j)
            continue;
        if (graph[vertex][j] <= firstMin)
        {
            secondMin = firstMin;
            firstMin = graph[vertex][j];
        }
        else if (graph[vertex][j] <= secondMin &&
                 graph[vertex][j] != firstMin)
            secondMin = graph[vertex][j];
    }
    return secondMin;
}

void TSPRecursive(int graph[SIZE][SIZE], int curr_bound, int curr_weight, int level, int curr_path[])
{
    if (level == SIZE)
    {
        if (graph[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + graph[curr_path[level - 1]][curr_path[0]];
            if (curr_res < final_res)
            {
                copyToFinalPath(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (graph[curr_path[level - 1]][i] != 0 && visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += graph[curr_path[level - 1]][i];
            if (level == 1)
                curr_bound -= ((findFirstMinimum(graph, curr_path[level - 1]) + findFirstMinimum(graph, i)) / 2);
            else
                curr_bound -= ((findSecondMinimum(graph, curr_path[level - 1]) + findFirstMinimum(graph, i)) / 2);
            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;
                TSPRecursive(graph, curr_bound, curr_weight, level + 1, curr_path);
            }
            curr_weight -= graph[curr_path[level - 1]][i];
            curr_bound = temp;
            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP(int graph[SIZE][SIZE])
{
    int curr_path[SIZE + 1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < SIZE; i++)
        curr_bound += (findFirstMinimum(graph, i) + findSecondMinimum(graph, i));
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    visited[0] = true;
    curr_path[0] = 0;
    TSPRecursive(graph, curr_bound, 0, 1, curr_path);
}

int main()
{
    int graph[SIZE][SIZE] = {{0, 10, 15, 20, 25},
                             {10, 0, 35, 25, 30},
                             {15, 35, 0, 30, 40},
                             {20, 25, 30, 0, 30},
                             {25, 30, 40, 30, 0}};
    TSP(graph);
    cout << "Minimum cost : " << final_res << endl;
    cout << "Path Taken : ";
    for (int i = 0; i <= SIZE; i++)
        cout << final_path[i] << " ";
    return 0;
}
