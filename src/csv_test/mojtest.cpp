#include "../csvReader.h"
#include <iostream>

int main() {

  try {

    csvReader myCSV;
    csvReader::csvResult res = myCSV.loadCSV("window_1k.csv");
    std::cout << std::endl;
    for (auto el : res.col_range) {
      std::cout << el.first << "  " << el.second << "     ";
    }
    std::cout << std::endl;
    for (auto el : res.row_range) {
      std::cout << el.first << "  " << el.second << "    ";
    }

    std::cout << std::endl;
    std::cout << res.csvArray << std::endl;
    std::cout << res.csvArray * 2 << std::endl;

    std::cout << myCSV.findValue(res, 5500, 440) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
};
