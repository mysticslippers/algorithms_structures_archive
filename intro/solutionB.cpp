#include <iostream>
#include <stack>

using namespace std;

int main() {
  string letters;
  cin >> letters;

  int size = letters.length() / 2;
  int map[100001];
  stack<char> dataSet;

  int trapPointer = -1;
  stack<int> trapsIndices;

  int animalPointer = 0;
  stack<int> animalsIndices;

  for (char letter : letters) {
    if (isupper(letter)) {
      trapsIndices.push(++trapPointer);
    } else {
      animalsIndices.push(++animalPointer);
    }

    if (!dataSet.empty()) {
      if ((toupper(letter) == toupper(dataSet.top())) &&
          ((isupper(letter) && islower(dataSet.top())) ||
           (islower(letter) && isupper(dataSet.top())))) {
        map[trapsIndices.top()] = animalsIndices.top();
        trapsIndices.pop();
        animalsIndices.pop();
        dataSet.pop();
      } else {
        dataSet.push(letter);
      }
    } else {
      dataSet.push(letter);
    }
  }

  if (!dataSet.empty()) {
    cout << "Impossible";
  } else {
    cout << "Possible" << endl;
    for (int i = 0; i < size; i++) {
      cout << map[i] << " ";
    }
  }
  return 0;
}
