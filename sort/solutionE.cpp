#include <iostream>

using namespace std;

bool isArranged(int* stalls, int size, int distance, int cows) {
  int lastPointer = 0;
  int counter = 1;

  for (int i = 1; i < size; i++) {
    if (stalls[i] - stalls[lastPointer] >= distance) {
      counter++;
      lastPointer = i;
      if (counter == cows) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int n, k;
  cin >> n >> k;

  int stalls[10001];
  for (int i = 0; i < n; i++) {
    cin >> stalls[i];
  }

  int distance = 0;
  int leftBorder = 1;
  int rightBorder = stalls[n - 1] - stalls[0];

  while (leftBorder <= rightBorder) {
    int mid = leftBorder + (rightBorder - leftBorder) / 2;
    if (isArranged(stalls, n, mid, k)) {
      distance = mid;
      leftBorder = mid + 1;
    } else {
      rightBorder = mid - 1;
    }
  }

  cout << distance << endl;
  return 0;
}
