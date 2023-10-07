#include <iostream>

#include "./structs.hpp"
#include "./native.hpp"
#include "./utils/helpers.hpp"
#include "./resolvers/methods.hpp"

using namespace std;

int main() {
  string text;
  int asciiTable[ASCII_LENGTH];
  Lue<char> list;

  initialize(list);
  initialize(asciiTable);

  cout << "Insert a text: ";
  getline(cin, text);

  counterRepeatCharacters(text, asciiTable);
  sortCharacters(list, asciiTable);
  Root<char> *huffmanTree = combineNodes(list);

  const string encondedText = getEncodedText(huffmanTree, text);
  const char decodedText = getDecodedText(huffmanTree, encondedText);

  cout << decodedText << endl;

  return 0;
}
