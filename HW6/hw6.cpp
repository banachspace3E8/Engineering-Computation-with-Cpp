#include "Vehicle.h"
#include "Truck.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

void addMember(vector<Truck>& Trcks, float currentDate){
  int limit =Trcks.size();
  for(int i = 0; i<limit; i++){
    Trcks.push_back(Truck(Trcks.at(i).getYear(), Trcks.at(i).getMiles(),
    Trcks.at(i).estimateValue(currentDate), Trcks.at(i).getManufacturer(),
    Trcks.at(i).getModel(),Trcks.at(i).getValue_Date(), Trcks.at(i).getAwd(),
    Trcks.at(i).getTowing_Capacity()));
  }
}

void valueUpdater(vector<Truck> Trcks, double date){
  for(auto elem:Trcks){
    elem.updateValue(date);
  }
}

double valueTotaller(vector<Truck> Trcks,double isum){
  vector<double> parallelTruckVal(Trcks.size());
  for(int i =0; i<Trcks.size();i++){
    parallelTruckVal.at(i)=Trcks.at(i).getValue();
  }
double sum = accumulate (parallelTruckVal.begin(), parallelTruckVal.end(),isum,
          [&](double a, double b){return (a + b);} );
  return sum;
}

vector<double> estimateVal(vector<Truck> Trcks, float estdYr, double isum){
  vector<double> parallelestdVal(Trcks.size());
  for(int i =0; i<Trcks.size();i++){
  parallelestdVal.at(i)=Trcks.at(i).estimateValue(estdYr);
  }

double sum = accumulate (parallelestdVal.begin(), parallelestdVal.end(),isum,
          [&](double a, double b){return (a + b);} );
          cout<<endl;
cout<<"The value of all the Trucks in 5 yrs is: $"<<sum<<endl;
  return parallelestdVal;
}

 void TruckSort(vector<Truck>& Trcks){
  sort(begin(Trcks),end(Trcks), [](Truck elem1,Truck elem2){return elem1.getName()<elem2.getName();});
   }

   void TruckSortMileage(vector<Truck>& Trcks){
    sort(begin(Trcks),end(Trcks), [](Truck elem1,Truck elem2){return elem1.getMiles()<elem2.getMiles();});
     }
  void printTruck(vector<Truck> Trcks){
     for(auto elem:Trcks){
     elem.printInfo();
     }
   }


int main(){
  vector <Truck> Trucks;
    Trucks.push_back(Truck(2017,500,180000,"Tesla","Semi",2017.00,"IWD", 80000));
    Trucks.push_back(Truck(2018,26.4,51140,"RAM","Laramie Chassis",2018.00,"4X4", 21000));
    Trucks.push_back(Truck(2019,21,39895,"Chevrolet","Silverado LD",2019.00,"4WD", 9200));
    Trucks.push_back(Truck(2019,19,51140,"Toyota","Tundra TRD Pro",2019.00,"4WD", 9400));
    Trucks.push_back(Truck(2019,23,60910,"GMC","Sierra 1500",2019.00, "4WD", 12200));

addMember(Trucks, 2019.25);
cout<<"The value of all the Trucks is: $"<<valueTotaller(Trucks,0)<<endl;
valueUpdater(Trucks, 2019.25);
vector<double> estdVal = estimateVal(Trucks,2024.25,0.0);
cout<<"The estimated values of all 10 trucks in 5 yrs are given below:"<<endl;
for(auto elem:estdVal){
cout<<"$ "<<elem<<endl;
}
cout<<endl;

auto updatedVector =Trucks;
cout<<"Trucks are printed below based on the getName() format: "<<endl;
printTruck(Trucks);
cout<<endl;
cout<<"The trucks are listed below according to alphabetical order:"<<endl;
TruckSort(updatedVector);
printTruck(updatedVector);

cout<<endl;
cout<<"The trucks are listed below according to increasing Mileage order:"<<endl;
auto moreUpdate = updatedVector;
TruckSortMileage(moreUpdate);
printTruck(moreUpdate);





  return 0;
}
