#pragma once
#include "wc_project.cpp"
#include <iostream>
#include <string>
#include <windows.h>

class wc_project {

  std::string name_;
  unsigned int id_;
  std::vector<windows *> allWindows;

public:
  wc_project(std::string &name) : name_{name} {}
  void addWindow(windows *ww) { allWindows.push_back(ww); }

  ~wc_project() {
    for (auto el : allWindows)
      delete el;
  }
};
