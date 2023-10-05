#include <iostream>

using namespace std;

template<typename T>
void initialize(Lue<T> &lue) {
  lue.start = NULL;
  lue.end = NULL;
}

void initialize(int asciiTable[]) {
  for (int index = 0; index < ASCII_LENGTH; index++) asciiTable[index] = 0;
}

template<typename T>
void reset(Lue<T> &list) {
  Node<T> *auxiliar = list.start;
  Node<T> *otherAuxiliar;

  while (auxiliar != NULL) {
    otherAuxiliar = auxiliar->connect;
    delete auxiliar;
    auxiliar = otherAuxiliar;
  }
}

template<typename T>
bool insert(Lue<T> &list, Root<T> *root) {
  Node<T> *newNode = new Node<T>;
  if (newNode == NULL) return false;

  newNode->root = root;
  newNode->connect = NULL;

  const bool isEmptyList = list.start == NULL || list.end == NULL;
  if (isEmptyList) {
    list.start = newNode;
    list.end = newNode;
    return true;
  }

  const int frequency = root->frequency;
  const bool isFirstNode = frequency < list.start->root->frequency;
  if (isFirstNode) {
    newNode->connect = list.start;
    list.start = newNode;
    return true;
  }

  const bool isLastNode = frequency >= list.end->root->frequency;
  if (isLastNode) {
    list.end->connect = newNode;
    list.end = newNode;
    return true;
  }

  Node<T> *auxiliar = list.start;

  while (auxiliar->root->frequency <= frequency && auxiliar->connect->root->frequency <= frequency) {
    auxiliar = auxiliar->connect;
  }

  newNode->connect = auxiliar->connect;
  auxiliar->connect = newNode;

  return true;
}
