#include <iostream>

using namespace std;

#define ASCII_LENGTH 256

template<typename T>
struct Root {
  T data;
  int frequency = 0;
  Root<T> *left = NULL, *right = NULL;
};

template<typename T>
struct Node {
  Root<T> *root;
  Node<T> *connect = NULL;
};

template<typename T>
struct Lue {
  Node<T> *start = NULL, *end = NULL;
};
