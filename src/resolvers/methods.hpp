#include <iostream>

using namespace std;

void counterRepeatCharacters(string text, int asciiTable[]) {
  for (int index = 0; index < text.length(); index++) {
    const int charIndex = (int)text[index];
    asciiTable[charIndex] +=1;
  }
}

template<typename T>
void sortCharacters(Lue<T> &list, int asciiTable[]) {
  for (int index = 0; index < ASCII_LENGTH; index++) {
    if (asciiTable[index] > 0) {
      Root<char> *root = new Root<char>;
      root->data = char(index);
      root->frequency = asciiTable[index];
      insert(list, root);
    }
  }
}

template<typename T>
Root<T> *combineNodes(Lue<T>& list) {
  while(!(list.start == NULL || list.start->connect == NULL)){
    Root<T> *firstValue = (list.start->root);
    Root<T> *secondValue = (list.start->connect->root);
    Root<T> *newRoot = new Root<T>;
    Node<T> *firstNodeToRemove = list.start;
    Node<T> *secondNodeToRemove = list.start->connect;

    const bool haveThirdConnect = list.start->connect->connect;

    if (haveThirdConnect) list.start = list.start->connect->connect;
    else list.start = NULL;

    delete firstNodeToRemove;
    delete secondNodeToRemove;

    newRoot->data = NULL;
    newRoot->frequency = firstValue->frequency + secondValue->frequency;
    newRoot->left = firstValue;
    newRoot->right = secondValue;
    insert(list, newRoot);
  }
  return list.start->root;
}

template<typename T>
bool findBitcodeOfHuffmanTree(Root<T> *tree, string &bitcode, T value) {
  if (tree == NULL) {
    bitcode = "";
    return false;
  }

  if (tree->data == value) return true;

  if (findBitcodeOfHuffmanTree(tree->left, bitcode, value)) {
    bitcode += "0";
    return true;
  }

  if (findBitcodeOfHuffmanTree(tree->right, bitcode, value)) {
    bitcode += "1";
    return true;
  }
}

template<typename T>
string getEncodedText(Root<T> *tree, string text) {
  string encodedText = "";
  for (int index = 0; index < text.length(); index++) {
    string bitcode = "";
    findBitcodeOfHuffmanTree(tree, bitcode, text[index]);
    bitcodeInverter(bitcode);
    encodedText += bitcode;
  }
  return encodedText;
}

template<typename T>
string getDecodedText(Root<T> *tree, string encodedText) {
  string decodedText = "";
  int index = 0;

  while (index < encodedText.length()) decodeBinaryToText(tree, encodedText, decodedText, index);

  return decodedText;
}

template<typename T>
void decodeBinaryToText(Root<T> *tree, const string &encodedText, string &decodedText, int &index) {
  if (tree->left == NULL && tree->right == NULL) {
    decodedText += tree->data;
    return;
  }

  if (index < encodedText.length()) {
    if (encodedText[index] == '0') {
      index++;
      decodeBinaryToText(tree->left, encodedText, decodedText, index);
    } else if (encodedText[index] == '1') {
      index++;
      decodeBinaryToText(tree->right, encodedText, decodedText, index);
    }
  }
}
