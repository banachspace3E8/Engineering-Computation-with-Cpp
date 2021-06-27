//Shishir Khanal
//CS 4499
//Purpose: cpp file for Vehicle Class
#include "Vehicle.h"
#include <Math.h>
#include <iostream>

//Overloaded Constructor
Vehicle::Vehicle(int year, int miles, int value, std::string manufacturer, std::string model, float value_date):
_Year(year), _Miles(miles), _Value(value), _Manufacturer(manufacturer), _Model(model), _Value_Date(value_date){}

//Default Constructor
Vehicle::Vehicle():_Year(2015),_Miles(55000), _Value(20000), _Manufacturer("Chevrolet"), _Model("Colorado"), _Value_Date(2019.17){}

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
float Vehicle::getValue_Date(){
  return _Value_Date;
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
void Vehicle::updateValue(float current_date){
  int diff = floor(current_date)-getValue_Date();
    double newVal = getValue();
  for(int i =0; i<diff; i++){
  newVal =newVal - 0.15*newVal;
  }
  _Value = (float)newVal;
  _Value_Date = current_date;
}

float Vehicle::estimateValue(float estdDate){
   int diff = floor(estdDate)-getValue_Date();
     double newVal = getValue();
   for(int i =0; i<diff; i++){
   newVal =newVal - 0.15*newVal;
   }
   return (float)newVal;
 }
