#include <iostream>
#include <map>

using namespace std;

void reversedSort(int weights[], char alphabet[]) {
  int weight, pointer;
  char letter;

  for (int i = 1; i < 26; i++) {
    weight = weights[i];
    letter = alphabet[i];
    pointer = i - 1;

    while (pointer > -1 && weight > weights[pointer]) {
      weights[pointer + 1] = weights[pointer];
      alphabet[pointer + 1] = alphabet[pointer];
      pointer--;
    }

    weights[pointer + 1] = weight;
    alphabet[pointer + 1] = letter;
  }
}

int main() {
  string letters;
  cin >> letters;

  int weights[26];
  for (int i = 0; i < 26; i++) {
    cin >> weights[i];
  }

  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  reversedSort(weights, alphabet);

  int counter[26];
  for (int i = 0; i < 26; i++) {
    counter[i] = 0;
  }

  map<char, int> resultMap;
  for (int i = 0; i < 26; i++) {
    char letter = alphabet[i];
    resultMap[letter] = i;
  }

  for (size_t i = 0; i < letters.size(); i++) {
    int count = resultMap[letters[i]];
    counter[count]++;
  }

  for (int i = 0; i < 26; i++) {
    if (counter[i] > 1) {
      cout << alphabet[i];
    }
  }

  for (int i = 0; i < 26; i++) {
    if (counter[i] == 1) {
      cout << alphabet[i];
    }
    if (counter[i] > 2) {
      for (int j = 0; j < counter[i] - 2; j++) {
        cout << alphabet[i];
      }
    }
    counter[i]--;
  }

  for (int i = 25; i > -1; i--) {
    if (counter[i] > 0) {
      cout << alphabet[i];
    }
  }

  return 0;
}
