#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int flowers[200001];
  for (int i = 0; i < n; i++) {
    cin >> flowers[i];
  }

  int repeat = 1, start = 0, end = 0;
  int result[2];
  result[0] = 0;
  result[1] = 0;
  for (int i = 1; i < n; i++) {
    if (flowers[i - 1] == flowers[i]) {
      repeat++;
      if (repeat == 3) {
        if ((end - start) > (result[1] - result[0])) {
          result[0] = start;
          result[1] = end;
        }
        start = i - 1;
        repeat = 2;
      }
    } else {
      repeat = 1;
    }
    end = i;
  }

  if ((end - start) > (result[1] - result[0])) {
    result[0] = start;
    result[1] = end;
  }

  cout << (result[0] + 1) << " " << (result[1] + 1) << endl;
  return 0;
}
