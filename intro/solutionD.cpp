#include <iostream>

using namespace std;

int main() {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;

  int total = 0;
  int previous = -1;
  for (int i = 0; i < k; i++) {
    total = a * b;
    if (total <= c) {
      total = 0;
      break;
    }
    total -= c;
    if (total > d) {
      total = d;
    }
    if (total == previous) {
      break;
    }
    previous = total;
    a = total;
  }
  cout << total;
  return 0;
}
