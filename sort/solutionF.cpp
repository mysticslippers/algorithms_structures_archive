#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compareStrings(string s1, string s2) {
  return s1 + s2 > s2 + s1;
}

int main() {
  vector<string> numbers;

  while (true) {
    string number;
    cin >> number;

    if (cin.eof()) {
      break;
    }

    if (numbers.size() == 0) {
      numbers.push_back(number);
      continue;
    }

    for (int i = numbers.size() - 1; i >= 0; i--) {
      if (compareStrings(numbers[i], number)) {
        numbers.insert(numbers.begin() + i + 1, number);
        break;
      }
      if (i == 0) {
        numbers.insert(numbers.begin(), number);
      }
    }
  }

  for (const string& num : numbers) {
    cout << num;
  }

  return 0;
}
