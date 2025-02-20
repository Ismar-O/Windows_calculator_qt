#pragma once
#include "csvReader.h"
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <xtensor/xarray.hpp>
#include <xtensor/xbuilder.hpp>
#include <xtensor/xio.hpp>

class csvReader {

  bool isNumber(const std::string &);

public:
  struct csvResult {
    std::map<double, size_t> col_range;
    std::map<double, size_t> row_range;
    xt::xarray<double> csvArray;
  };
  csvResult loadCSV(const std::string &);
  double findValue(csvResult &, double, double);
};
