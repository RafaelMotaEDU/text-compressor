#include <iostream>

using namespace std;

void counterRepeatCharacters(string text, int asciiTable[]) {
  for (int index = 0; index < text.length(); index++) {
    const int charIndex = (int)text[index];
    asciiTable[charIndex] +=1;
  }
}
