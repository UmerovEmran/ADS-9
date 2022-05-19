// Copyright 2021 NNTU-CS
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> itog;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return itog;
  }
  char prom;
  std::string prov = "";
  while (!file.eof()) {
    prom = file.get();
    if (prom <= 'Z' && prom >= 'A') {
      prom = prom + ('a' - 'A');
    }
    if (prom <= 'z' && prom >= 'a') {
      prov += prom;
    } else {
        itog.add(prov);
        prov = "";
      }
  }
  return itog;
}

