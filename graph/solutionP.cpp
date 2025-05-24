#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void DFS(int n, const vector<vector<bool>>& graph, int start, vector<bool>& visited, int& counter) {
  visited[start] = true;
  counter++;

  for (int i = 0; i < n; i++) {
    if (graph[start][i] && !visited[i]) {
      DFS(n, graph, i, visited, counter);
    }
  }
}

void reversedDFS(
    int n, const vector<vector<bool>>& graph, int start, vector<bool>& visited, int& counter
) {
  visited[start] = true;
  counter++;

  for (int i = 0; i < n; i++) {
    if (graph[i][start] && !visited[i]) {
      reversedDFS(n, graph, i, visited, counter);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      graph[i].push_back(temp);
    }
  }

  vector<vector<bool>> searchGraph;
  vector<bool> visited;

  int l = 0;
  int r = 2000000000;
  while (l < r) {
    int m = (l + r) / 2;

    searchGraph.clear();
    searchGraph.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        searchGraph[i].push_back(graph[i][j] <= m);
      }
    }

    visited.clear();
    visited.resize(n, false);
    int counter = 0;
    DFS(n, searchGraph, 0, visited, counter);
    visited.clear();
    visited.resize(n, false);
    int reversedCounter = 0;
    reversedDFS(n, searchGraph, 0, visited, reversedCounter);

    if (counter == n && reversedCounter == n) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << l << endl;
  return 0;
}
