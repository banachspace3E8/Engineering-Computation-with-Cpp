//For line
#include <iostream>
//for mathematical functions
#include <cmath>
#include <random>
//For Trapezoidal Method
#include <c:/Users/User/Documents/boost_1_70_0/boost_1_70_0/boost/math/quadrature/trapezoidal.hpp>
//For finding max of function
#include <C:/Users/User/Documents/boost_1_70_0/boost_1_70_0/boost/math/tools/minima.hpp>

using namespace std;
namespace quad = boost::math::quadrature;
namespace min = boost::math::tools;


//Numerical Integration using Trapezoidal Method
float intTrapez(auto fx, double a, double b){
  return quad::trapezoidal(fx,a , b);
}

//Find the local minimum value of a function
double findMin(auto fx, double bVal, double eVal){
  int bits = numeric_limits<double>::digits;
  std::pair<double, double> r = min::brent_find_minima(fx, bVal, eVal, bits);
  cout.precision(numeric_limits<double>::digits10);
  cout<<endl;
  cout << "(E,P(E))) = (" << r.first << "," << r.second << ")"<< endl;
  return r.second;
}

//checks if the probability value of the point lies below the PDF curve
bool pairSelect(pair<double, double> point, double max, auto fx){
    double boundary = fx(point.first);
return point.second < boundary;
}

int main(){
  //Lambda for PDF & normalized Reciprocal of PDF
auto fx = [](const double& E){return (0.4865*sinh(sqrt(2*E))*exp(-E));};
auto recfx = [](const double& E){return (0.12658/(0.4865* sinh(sqrt(2*E))*exp(-E)));};//Normalized reciprocal
//Range of Eneries
double bVal = 0.0;
double eVal =8.0;
//check if PDF is normalized
cout<<"The Integral of the PDF in the range[0,8] is: "<<intTrapez(fx,bVal,eVal)<<endl;
cout<<"This is almost equal to 1.00. Hence, we know that this is a normalized function."<<endl;

double maximum = findMin(recfx, bVal,eVal);// max of fx is min of recfx
// Random Engine
default_random_engine generator(100);
uniform_real_distribution<double> dist(0,8);
  uniform_real_distribution<double> dist1(0, maximum);
double x = dist(generator);
double y = dist1(generator);
//point initialization
pair<double, double> point(x,y);
cout<<endl;
cout<<"Random Energy is :"<<point.first<<" and Random Probability is: "<<point.second<<endl;
//declatation of vector sample
vector<double> sample;
//create 100,000 random points
for(int i = 0; i<100000; i++){
  pair<double, double> point(dist(generator),dist1(generator));
  if(pairSelect(point, maximum, fx)==1){
    //if point lies below PDF curve then add it to the sample
    sample.push_back(point.first);
  }
}
cout<<endl;
cout<<"The size of the sample vector is: "<<sample.size()<<endl;
//Create Bins
vector<double> Bins(100,0);

for(int i=0; i<sample.size(); i++){
  // 100/8 = 12.5; (int)sample*12.5 =>bin number; % Works for equidistant bins
  Bins.at(static_cast<int>(sample[i]*12.5))++;
}
//Print sizes of bins
cout<<endl;
cout<<"The sizes of:"<<endl;
for(int i = 0;i<Bins.size();i++){
cout<<"Bin "<<i+1<<" is: "<<Bins.at(i)<<endl;
 }

  return 0;
}
