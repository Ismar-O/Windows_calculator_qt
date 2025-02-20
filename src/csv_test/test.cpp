#include "../windows.h"
#include <exception>
#include <iostream>

int main() {
  window_1k newWindow;
  newWindow.setWidth(400);
  newWindow.setHeight(500);
  try {
    std::cout << newWindow.calculatePrice() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
