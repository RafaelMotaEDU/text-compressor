/* 
  Disciplina: Estruturas de Dados
  Professor: Marcos Cesar Cardoso Carrard
  Alunos: Rafael Mota Alves e Daniel Sansão Araldi
*/

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
Root<T> *createHuffmanTree(Lue<T>& list) {
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

  while (index < encodedText.length()) binaryToText(tree, encodedText, decodedText, index);

  return decodedText;
}

template<typename T>
void binaryToText(Root<T> *tree, const string &encodedText, string &decodedText, int &index) {
  if (tree->left == NULL && tree->right == NULL) {
    decodedText += tree->data;
    return;
  }

  if (index < encodedText.length()) {
    if (encodedText[index] == '0') {
      index++;
      binaryToText(tree->left, encodedText, decodedText, index);
    } else if (encodedText[index] == '1') {
      index++;
      binaryToText(tree->right, encodedText, decodedText, index);
    }
  }
}


string menu(){
    int option = -1;
    string text;

    do{
        cout << "Choose this options:" << endl;
        cout << "1. Text compress" << endl;
        cout << "2. File text compress" << endl;
        cout << "3. Exit" << endl;
        cin >> option;

        cin.ignore();

        switch(option){
            case 1: {
                cout << "Insert a text: ";
                getline(cin, text);
                return text;
                break;
            }
            case 2: {
                std::ifstream file;
                file.open("./files/example.txt");
                if(file.is_open()){
                    while(getline(file, text)){
                        return text;
                    }
                    file.close();
                } else {
                    cout << "Unable to open file";
                    return "";
                }
                break;
            }
            case 3: {
                cout << "Bye bye!" << endl;
                return "";
            }
            default: {
                cout << "Invalid option! Try again" << endl;
                system("pause");
                system("cls");
                break;
            }

        }
    }while (option != 3);
}
