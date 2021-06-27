//Shishir Khanal
//CS 4499
//Purpose: Create pointers and apply Truck and Vehicle classes
#include <iostream>
#include <vector>

#include "Vehicle.h"
#include "Truck.h"
using namespace std;

vector <float> estVal(vector<Truck> const& Truk,float const& someDate){
vector <float> Values(Truk.size());
cout<<endl<<"The estimated values for the 5 trucks are: "<<endl;
for(int i = 0; i<Truk.size(); i++){
  Truck T = Truk[i];
Values[i] = T.estimateValue(someDate);
}
return Values;
}

int main(){

int x;
int y;
int* p1;
p1 = &x;
*p1 = 99;
cout<<"The value of x using 'x' is: "<<x<<endl;
cout<<"The value of x using 'p1' is: "<<*p1<<endl;
p1 = &y;
*p1 = -300;
//cout<<"The value of y using 'p1' is: "<<y<<endl;
Truck Truck1 = Truck(2015,0,37000,"Chevrolet","Colorado",2015.50,"4X4", 5000);
Truck1.updateValue(2019.08);
cout<<"Value of Chevrolet Colorado on "<<Truck1.getValue_Date()<<" is "<<"$ "<<Truck1.getValue()<<endl;

vector <Truck> Trucks;
  Trucks.push_back(Truck(2017,500,180000,"Tesla","Semi",2019.08,"IWD", 80000));
  Trucks.push_back(Truck(2018,26.4,51140,"RAM","Laramie Chassis",2019.08,"4X4", 21000));
  Trucks.push_back(Truck(2019,21,39895,"Chevrolet","Silverado LD",2019.08,"4WD", 9200));
  Trucks.push_back(Truck(2019,19,51140,"Toyota","Tundra TRD Pro",2019.08,"4WD", 9400));
  Trucks.push_back(Truck(2019,23,60910,"GMC","Sierra 1500",2019.08, "4WD", 12200));

vector <float> values;
// April 1 2022 => 2022.25
values = estVal(Trucks, 2022.25);
for (int i = 0; i< values.size();i++){
  cout<<values[i]<<endl;
}
return  0;
}
