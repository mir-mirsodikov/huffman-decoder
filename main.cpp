/**
 * Mirmukhammad Mirsodikov
 * Homework 8
    - From your code for hw 7, output Huffman coding scheme to a file (huff.sch).
    - Open the scheme file, load coding scheme into a certain data structure.
    - Open the encoded file, use coding scheme to decode the encoded file.
    - Output plain text (after decoding) to pride_decoded.txt. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <map>
using namespace std;

map<string, string> getEncodingScheme(const string fileName) {
  map<string, string> encodingScheme;
  ifstream fileRead;

  fileRead.open(fileName);
  if (fileRead.is_open()) {
    string prefix;
    string character;
    while (!fileRead.eof()) {
      getline(fileRead, prefix);
      getline(fileRead, character);
      encodingScheme[prefix] = character;
    }
    fileRead.close();
  }

  return encodingScheme;
}

void decodeFile(const string encodedFile, map<string, string> encodingScheme) {
  ifstream fileRead;
  ofstream fileWrite;

  fileRead.open(encodedFile);
  if (fileRead.is_open()) {
    char fileCharacter;
    string character;
    fileWrite.open("pride_decoded.txt");
    while (!fileRead.eof()) {
      fileRead.get(fileCharacter);
      character += fileCharacter;
      if (encodingScheme.count(character) != 0) {
        if (encodingScheme[character] == "") {
          fileWrite << endl;
        }
        else {
          fileWrite << encodingScheme[character];
        }
        character = "";
      }
    }
  }
}

int main() {
  const string huffSchemeFile = "huff.sch";
  const string huffEncodedFile = "pride.huff";
  map<string, string> encodingScheme = getEncodingScheme(huffSchemeFile);

  decodeFile(huffEncodedFile, encodingScheme);
}