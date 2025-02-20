#pragma once
#include "csvReader.h"
#include "windows.h"
#include <cstddef>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// CSV Reader can read csv files and output windowsPriceSheet
// which contains h/w ranges and coresponding prices.

class csvReader {

  bool isNumber(const std::string &);

public:
  windowsPriceSheet loadCSV(const std::string &);
  std::vector<windowsPriceSheet> loadAllCSV(const std::string &);
  double findValue(windowsPriceSheet &, double, double);
};
