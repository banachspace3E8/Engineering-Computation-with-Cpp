//Shishir Khanal
//CS 4499
//Purpose: Header file for Truck Class
#pragma once
#include "Vehicle.h"
#include <string>

//Derived Class Truck, Base class Vehicle
class Truck: public Vehicle{
private:
  std::string _Awd;
  int _Towing_Capacity;

public:
  //Constructors
  Truck(int year,int miles, int value, std::string manufacturer, std::string model, std::string awd, int towing_capacity);
  Truck();
  //getters
  int getTowing_Capacity();
  std::string getAwd();
  //setters
  void setTowing_Capacity(int towing_capacity);
  void setAwd(std::string awd);
};
