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

map<string, wchar_t> getEncodingScheme(const string fileName) {
  map<string, wchar_t> encodingScheme;
  ifstream fileRead;

  fileRead.open(fileName);
  if (fileRead.is_open()) {
    wchar_t fileCharacer;
    string line;
    while (!fileRead.eof()) {
      getline(fileRead, line);
      cout << line << endl;
    }

    fileRead.close();
  }

  return encodingScheme;
}

int main() {
  const string huffSchemeFile = "huff.sch";
  const string huffEncodedFile = "pride.huff";
  map<string, wchar_t> encodingScheme = getEncodingScheme(huffSchemeFile);
}