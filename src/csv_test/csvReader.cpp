#include "csvReader.h"

bool csvReader::isNumber(const std::string &str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

csvReader::csvResult csvReader::loadCSV(const std::string &filename) {

  csvResult res;
  std::vector<std::vector<double>> tempVec;
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error{"Could not open file " + filename};
  }

  std::string line;
  std::string value;
  std::getline(file, line);
  while (line.empty() || line[0] == '#') {
    std::getline(file, line);
  }

  std::stringstream sstream(line);
  while (getline(sstream, value, ',')) {
    static int counter;
    if (isNumber(value))
      res.col_range[std::stod(value)] = counter++;
    else if (counter) {
      throw std::invalid_argument{"Column range is NaN in file" + filename +
                                  " -> " + value};
    }
  }

  while (std::getline(file, line)) {

    if (line.empty() || line[0] == '#') {
      continue;
    }
    static int counter;
    std::string value;
    std::stringstream sstream(line);
    std::getline(sstream, value, ',');
    if (isNumber(value)) {
      res.row_range[std::stod(value)] = counter++;
    } else if (counter) {
      throw std::invalid_argument{"Row range is NaN in file " + filename};
    }
    std::vector<double> row;

    while (std::getline(sstream, value, ',')) {
      if (isNumber(value))
        row.push_back(std::stod(value));
      else
        throw std::invalid_argument{"Value of field in file " + filename +
                                    " is NaN -> " + value};
    }
    tempVec.push_back(row);
  }

  file.close();
  auto rows = tempVec.size();
  auto cols = tempVec[0].size();
  res.csvArray = xt::zeros<double>({rows, cols});

  for (size_t i = 0; i < rows; ++i) {
    for (size_t k = 0; k < cols; ++k) {
      res.csvArray(i, k) = tempVec[i][k];
    }
  }

  return res;
}

double csvReader::findValue(csvResult &res, double width, double height) {
  auto w_range = res.col_range.upper_bound(width);
  if (w_range == res.col_range.end()) {
    throw std::invalid_argument{"Width is out of range. Max width is " +
                                std::to_string((--w_range)->first)};
  }
  std::cout << w_range->first << "  -> " << w_range->second << std::endl;
  auto h_range = res.row_range.upper_bound(height);
  if (h_range == res.row_range.end()) {
    throw std::invalid_argument("Height is out of range. Max width is " +
                                std::to_string((--h_range--)->first));
  }
  std::cout << h_range->first << "  ->  " << h_range->second << std::endl;
  return res.csvArray(h_range->second, w_range->second);
}
