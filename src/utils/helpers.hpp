#include <iostream>

using namespace std;

void show(int numbers[]) {
  for (int index = 0; index < ASCII_LENGTH; index++) cout << numbers[index];
}

template <typename T>
void show(Lue<T> list) {
  Node <T> *auxiliar = list.start;
  while (auxiliar != NULL) {
    cout << auxiliar->root->data << ":" << auxiliar->root->frequency << " ";
    auxiliar = auxiliar->connect;
  }
}

void bitcodeInverter(string &bitcode){
    string bitCodeInverted = "";
    for(int index = bitcode.length() - 1; index >= 0; index--){
        bitCodeInverted += bitcode[index];
    }
    bitcode = bitCodeInverted;
}

