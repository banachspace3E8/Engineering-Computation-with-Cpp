//Shishir Khanal
//CS 4499
//Purpose: Header file for Vehicle Class
#pragma once
#include <string>

class Vehicle {
private:
 int _Year;
 int _Miles;
 int _Value;
std::string _Manufacturer;
std::string _Model;

public:
  //Overloaded Constructor
  Vehicle(int year,int miles, int value, std::string manufacturer, std::string model);
  //Default constructor
  Vehicle();
  //getters
  int getYear();
  int getMiles();
  int getValue();
  std::string getManufacturer();
  std::string getModel();
  //setters
  void setYear(int year);
  void setMiles(int miles);
  void setValue(int value);
  void setManufacturer(std::string manufacturer);
  void setModel(std::string model);
};
