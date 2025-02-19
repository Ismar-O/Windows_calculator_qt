#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

enum System { SYSTEM_1, SYSTEM_2, SYSTEM_3 };
enum Color { COLOR_1, COLOR_2, COLOR_3 };
enum Glass { GLASS_1, GLASS_2, GLASS_3 };

class windows {

  unsigned int height_;
  unsigned int width_;
  System system;
  Color color;
  Glass glass;
  std::string uniqeId;
  double price_;

protected:
  windows();

public:
  void setHeight(unsigned int h) { height_ = h; }
  void setWidth(unsigned int w) { width_ = w; }
  unsigned int getHeight() { return height_; }
  unsigned int getWidth() { return width_; }

  void setColor(Color &toSetColor) { color = toSetColor; };
  void setSystem(System &toSetSystem) { system = toSetSystem; }
  void setGlass(Glass &toSetGlass) { glass = toSetGlass; }
  Color getColor() { return color; }
  System getSystem() { return system; }
  Glass getGlass() { return glass; }

  virtual std::string calculateId();
  virtual double calculatePrice();
};

class window_1k : public windows {
public:
  std::string calculateId() override;
  virtual double calculatePrice() override;
};

class window_2k : public windows {
public:
  std::string calculateId() override;
  virtual double calculatePrice() override;
};
