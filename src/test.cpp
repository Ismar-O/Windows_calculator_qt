#include "csvReader.h"
#include <iostream>

int main() {

  csvReader myReader;
  auto sh = myReader.loadAllCSV("csvFiles");

  std::cout << sh[0].array << std::endl;
  std::cout << sh[1].array << std::endl;
}
