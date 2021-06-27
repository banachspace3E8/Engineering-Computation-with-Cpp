//Shishir Khanal
//CS 4499
//Purpose: cpp file for Vehicle Class
#include "Vehicle.h"
#include <iostream>

//Overloaded Constructor
Vehicle::Vehicle(int year, int miles, int value, std::string manufacturer, std::string model):
_Year(year), _Miles(miles), _Value(value), _Manufacturer(manufacturer), _Model(model){}

//Default Constructor
Vehicle::Vehicle():_Year(2015),_Miles(55000), _Value(20000), _Manufacturer("Chevrolet"), _Model("Colorado"){}

//getters
int Vehicle::getYear(){
  return _Year;
}
int Vehicle::getMiles(){
  return _Miles;
}
int Vehicle::getValue(){
  return _Value;
}
std::string Vehicle::getManufacturer(){
  return _Manufacturer;
}
std::string Vehicle::getModel(){
  return _Model;
}
//Setters
void Vehicle::setYear(int year){
  _Year = year;
}
void Vehicle::setMiles(int miles){
  _Miles = miles;
}
void Vehicle::setValue(int value){
  _Value = value;
}
void Vehicle::setManufacturer(std::string manufacturer){
  _Manufacturer = manufacturer;
}
void Vehicle::setModel(std::string model){
  _Model = model;
}
