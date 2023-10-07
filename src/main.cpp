/* 
  Disciplina: Estruturas de Dados
  Professor: Marcos Cesar Cardoso Carrard
  Alunos: Rafael Mota Alves e Daniel Sansão Araldi
*/

#include <iostream>
#include <fstream>

#include "./structs.hpp"
#include "./native.hpp"
#include "./utils/helpers.hpp"
#include "./resolvers/methods.hpp"

using namespace std;

int main() {
  int asciiTable[ASCII_LENGTH];
  Lue<char> list;

  initialize(list);
  initialize(asciiTable);

  const string text = menu();
  if(text == "") return 0;

  counterRepeatCharacters(text, asciiTable);
  sortCharacters(list, asciiTable);
  Root<char> *huffmanTree = createHuffmanTree(list);

  const string encodedText = getEncodedText(huffmanTree, text);
  const string decodedText = getDecodedText(huffmanTree, encodedText);

  cout << endl << "Encoded Text: ";
  cout << encodedText << endl;

  cout << endl << "Decoded (Original) Text: ";
  cout << decodedText << endl;

  return 0;
}
