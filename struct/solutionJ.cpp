#include <deque>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  deque<string> firstQueue;
  deque<string> secondQueue;

  for (int i = 0; i < n; i++) {
    char operation;
    cin >> operation;

    if (operation == '-') {
      cout << firstQueue.front() << endl;
      firstQueue.pop_front();
    } else {
      string number;
      cin >> number;
      if (operation == '+') {
        secondQueue.push_back(number);
      } else {
        secondQueue.push_front(number);
      }
    }

    int difference = firstQueue.size() - secondQueue.size();
    if (difference == 2) {
      secondQueue.push_front(firstQueue.back());
      firstQueue.pop_back();
    } else if (difference == -1) {
      firstQueue.push_back(secondQueue.front());
      secondQueue.pop_front();
    }
  }

  return 0;
}
