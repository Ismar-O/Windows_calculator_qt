#pragma once
#include "wc_project.cpp"
#include <iostream>
#include <string>

class wc_project {

  std::string name_;
  unsigned int id_;

public:
  wc_project(std::string &name) : name_{name} {}
};
