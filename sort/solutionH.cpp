#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  sort(prices.begin(), prices.end());

  long long total = 0;
  for (int i = n - 1; i >= 0; i--) {
    if ((n - i) % k != 0) {
      total += prices[i];
    }
  }

  cout << total << endl;
  return 0;
}
