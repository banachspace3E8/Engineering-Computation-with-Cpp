//Shishir Khanal
//CS 4499
//Purpose: To create vector of Trucks and display on window
//FYI: Proper formatting of table visible when cygwin is in full screen
#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Truck.h"
using namespace std;

int main(){
//Create a vector of Trucks
  vector <Truck> Trucks;
//Add Trucks to the vector
  //Source:https://www.tesla.com/semi
  Trucks.push_back(Truck(2017,500,180000,"Tesla","Semi","IWD", 80000));
  //Source:https://www.ramtrucks.com/build.chassis_cab_3500.2018#/models/zipcode/83201/vehicle/CUT201816/ccode/CUT201816DD8L93D/llp/2TH/options/ESB,DFP,TV2,WF7,VL,DMF,Z8H,UAS,U1,PW7,22H,XBM,APA
  //       http://www.fuelly.com/car/ram/3500/2018/katson01/885061
      Trucks.push_back(Truck(2018,26.4,51140,"RAM","Laramie Chassis","4X4", 21000));
  //Source:https://www.chevrolet.com/previous-model/silverado-1500-pickup-truck/build-and-price/config?styleId=398577
  Trucks.push_back(Truck(2019,21,39895,"Chevrolet","Silverado LD","4WD", 9200));
  //Source:https://www.toyota.com/tundra/features/mpg/8240/8252/8275
    Trucks.push_back(Truck(2019,19,51140,"Toyota","Tundra TRD Pro","4WD", 9400));
//Source:https://www.gmc.com/trucks/sierra-1500-pickup-truck
    Trucks.push_back(Truck(2019,23,60910,"GMC","Sierra 1500","4WD", 12200));
//Display the table on the board
//Display title of Table
cout<< "Year"<<"    Miles (MPG)"<<"    Value ($)"<<"    Manufacturer"<<"    Model"<< "             AWD"<<"         Max Towing Capacity(lbs)"<<endl;
//Get the truck information and print on the screen
  cout<<Trucks.at(0).getYear()<<"    "<<Trucks.at(0).getMiles()<<"             "<<Trucks.at(0).getValue()<<"        "<<Trucks.at(0).getManufacturer()<<"         "<<Trucks.at(0).getModel()<<"              "<<Trucks.at(0).getAwd()<<"           "<<Trucks.at(0).getTowing_Capacity()<<endl;
  cout<<Trucks.at(1).getYear()<<"    "<<Trucks.at(1).getMiles()<<"              "<<Trucks.at(1).getValue()<<"         "<<Trucks.at(1).getManufacturer()<<"          "<<Trucks.at(1).getModel()<<"    "<<Trucks.at(1).getAwd()<<"           "<<Trucks.at(1).getTowing_Capacity()<<endl;
  cout<<Trucks.at(2).getYear()<<"    "<<Trucks.at(2).getMiles()<<"              "<<Trucks.at(2).getValue()<<"         "<<Trucks.at(2).getManufacturer()<<"    "<<Trucks.at(2).getModel()<<"       "<<Trucks.at(2).getAwd()<<"           "<<Trucks.at(2).getTowing_Capacity()<<endl;
  cout<<Trucks.at(3).getYear()<<"    "<<Trucks.at(3).getMiles()<<"              "<<Trucks.at(3).getValue()<<"         "<<Trucks.at(3).getManufacturer()<<"       "<<Trucks.at(3).getModel()<<"     "<<Trucks.at(3).getAwd()<<"           "<<Trucks.at(3).getTowing_Capacity()<<endl;
  cout<<Trucks.at(4).getYear()<<"    "<<Trucks.at(4).getMiles()<<"              "<<Trucks.at(4).getValue()<<"         "<<Trucks.at(4).getManufacturer()<<"          "<<Trucks.at(4).getModel()<<"        "<<Trucks.at(4).getAwd()<<"           "<<Trucks.at(4).getTowing_Capacity()<<endl;
  return 0;
}
