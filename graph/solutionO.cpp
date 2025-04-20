#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool BFS(const vector<vector<int>>& graph, int start, vector<int>& parts) {
  queue<int> visitQueue;
  visitQueue.push(start);
  parts[start] = 1;

  while (!visitQueue.empty()) {
    int current = visitQueue.front();
    visitQueue.pop();

    for (int neighbour : graph[current]) {
      if (parts[neighbour] == 0) {
        parts[neighbour] = -parts[current];
        visitQueue.push(neighbour);
      } else if (parts[neighbour] == parts[current]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;

    graph[first - 1].push_back(second - 1);
    graph[second - 1].push_back(first - 1);
  }

  vector<int> parts(n, 0);
  bool state = true;

  for (int i = 0; i < n; i++) {
    if (parts[i] == 0) {
      state = BFS(graph, i, parts);
      if (!state) {
        break;
      }
    }
  }

  cout << (state ? "YES" : "NO") << endl;
  return 0;
}
