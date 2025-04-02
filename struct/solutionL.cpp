#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  deque<int> deque;
  for (int i = 0; i < n; i++) {
    if (!deque.empty() && deque.front() < i - k + 1) {
      deque.pop_front();
    }

    while (!deque.empty() && numbers[deque.back()] > numbers[i]) {
      deque.pop_back();
    }
    deque.push_back(i);

    if (i >= k - 1) {
      cout << numbers[deque.front()] << " ";
    }
  }

  return 0;
}
