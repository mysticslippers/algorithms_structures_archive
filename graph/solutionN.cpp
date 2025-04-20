#include <iostream>
#include <vector>

using namespace std;

int DFS(
    const vector<vector<int>>& graph, int currentNode, vector<bool>& visited, vector<bool>& cache
) {
  cache[currentNode] = true;
  for (int neighbour : graph[currentNode]) {
    if (visited[neighbour]) {
      return 0;
    }
    if (cache[neighbour]) {
      return 1;
    }
    return DFS(graph, neighbour, visited, cache);
  }
  return 0;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    graph[i].push_back(temp - 1);
  }

  int result = 0;
  vector<bool> visited(n, false);
  vector<bool> cache(n, false);

  for (int i = 0; i < n; i++) {
    fill(cache.begin(), cache.end(), false);
    result += DFS(graph, i, visited, cache);
    for (int j = 0; j < n; j++) {
      if (cache[j]) {
        visited[j] = true;
      }
    }
  }

  cout << result << endl;
  return 0;
}
