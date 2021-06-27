//Shishir Khanal
//CS 4499
//Purpose: cpp file for Truck Class
#include "Truck.h"
#include <iostream>

//Constructors
Truck::Truck(int year,int miles, int value, std::string manufacturer, std::string model,float value_date, std::string awd, int towing_capacity):
Vehicle(year, miles, value, manufacturer, model, value_date), _Awd(awd), _Towing_Capacity(towing_capacity){}

Truck::Truck():Vehicle(), _Awd("4X4"), _Towing_Capacity(5000){}

//getters
std::string Truck::getName(){
  return std::to_string(getYear())+"  "+getManufacturer()+"  "+getModel()+"  "+getAwd();
}

std::string Truck::getAwd(){
  return _Awd;
}
int Truck::getTowing_Capacity(){
  return _Towing_Capacity;
}

//Setters
void Truck::setAwd(std::string awd){
  _Awd = awd;
}
void Truck::setTowing_Capacity(int towing_capacity){
  _Towing_Capacity = towing_capacity;
}

//Methods

void Truck::printInfo(){
std::cout<<getName()<<std::endl;
}
