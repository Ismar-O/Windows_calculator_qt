#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

xt::xarray<double> loadCSV(const std::string &filename) {

  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filename);
  }

  std::vector<std::vector<double>> data; // Store rows of CSV
  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::vector<double> row;
    std::string value;

    while (std::getline(ss, value, ',')) { // Read each comma-separated value
      row.push_back(std::stod(value));     // Convert to double
    }
    data.push_back(row);
  }

  file.close();

  // Convert std::vector to xt::xarray
  size_t rows = data.size();
  size_t cols =
      data[0].size(); // Assuming all rows have the same number of columns

  xt::xarray<double> matrix = xt::zeros<double>({rows, cols});
  for (size_t i = 0; i < rows; ++i)
    for (size_t j = 0; j < cols; ++j)
      matrix(i, j) = data[i][j];

  return matrix;
}

int main() {
  try {
    xt::xarray<double> priceMatrix = loadCSV("test3.csv");
    std::cout << "Loaded Matrix:\n" << priceMatrix << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }
  return 0;
}
