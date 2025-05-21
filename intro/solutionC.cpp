#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int currentHash = 0;
  map<string, int> hashMap;

  const int CACHE_PERIOD = 1000;
  vector<map<int, int>> callStack;
  callStack.push_back(map<int, int>());

  while (true) {
    string current;
    cin >> current;
    if (cin.eof()) {
      break;
    }

    if (current == "{") {
      if (callStack.size() % CACHE_PERIOD == 0) {
        map<int, int> tempMap;
        for (size_t i = callStack.size() - CACHE_PERIOD; i < callStack.size(); i++) {
          for (auto& var : callStack[i]) {
            tempMap[var.first] = var.second;
          }
        }
        callStack.push_back(map<int, int>(tempMap));
      } else {
        callStack.push_back(map<int, int>());
      }
    } else if (current == "}") {
      callStack.pop_back();
    } else {
      int delimiter = current.find('=');
      string leftPart = current.substr(0, delimiter);
      string rightPart = current.substr(delimiter + 1);

      if (hashMap.count(leftPart) == 0) {
        hashMap[leftPart] = currentHash++;
      }
      int leftHash = hashMap[leftPart];

      if (rightPart.find_first_of("0123456789") != string::npos) {
        callStack.back()[leftHash] = stoi(rightPart);
      } else {
        if (hashMap.count(rightPart) == 0) {
          hashMap[rightPart] = currentHash++;
        }
        int rightHash = hashMap[rightPart];

        for (int i = callStack.size() - 1; i >= 0; i--) {
          if (callStack[i].count(rightHash)) {
            callStack.back()[leftHash] = callStack[i][rightHash];
            cout << callStack[i][rightHash] << endl;
            break;
          }
          if (i % CACHE_PERIOD == 0) {
            callStack.back()[leftHash] = 0;
            cout << "0" << endl;
          }
        }
      }
    }
  }

  return 0;
}
