//Name: Shishir Khanal
//CS 4499
//Homework 2
//Purpose:
//     1. Program to calculate & display the volume of a washer
//     2. Program to create LCG

#include <iostream>
#include <math.h>

using namespace std;

//funcion prototype
double washerVolume(double,double, double);
double randlcg(int, int, int, int);
void dispMenu();

int main(){
//main function
dispMenu();
//display menu
int option=0;
cin>>option;
//prompt user to choose an option
if (option == 1) {
  double outRad =0.0;
  double inRad =0.0;
  double washerVol =0.0;
  double height = 0.0;
  //variable creation and initialization
  cout<<"What is the outer radius of your washer?"<<endl;
  cin>>outRad;
  cout<<"What is the inner radius of your washer?"<<endl;
  cin>>inRad;
  cout<<"What is the height of your washer?"<<endl;
  cin>>height;
  //prompt user for washer dimensions
  cout<<"The volume of your washer is "<<washerVolume(outRad,inRad,height)<<" units^3"<<endl;
  //display volume of washer
  cout<<endl;
  cout<<"Now that you have the volume of the washer,"<<endl;
  return main();
  //recursion of main function
}
 if (option == 2){
int multiplier =61;
int adder = 1;
long int modul =2^24;
int seed = 100001;
//creation an initialization of variables
for(int i = 0; i<30; i++){
  if (i==0){
    //calculate the first random number using seed
    printf("%.1f", randlcg(seed, multiplier, adder, modul)/modul);
    cout<<endl;
}
  else{
    //calculate the next random numbers unsing previous random numbers
    seed = randlcg(seed, multiplier, adder, modul);
    printf("%.1f", randlcg(seed, multiplier, adder, modul)/modul);
    cout<<endl;
  }
}
cout<<"Now that you have the random numbers,"<<endl;
return main();
//resursion of main function
 }

 if (option == 3) exit(EXIT_SUCCESS);
//exit option
else{
  cout<<"Your choice could not be recognized. Please Try Again!"<<endl;
  return main();
  //check for unrecognized options
}
  return 0;
}
//---------------------------------------------------------------------
void dispMenu(){
  //displays menu to user
  cout<<"What would you like to do?"<<endl;
  cout<<"1. Calculate the volume of a washer"<<endl;
  cout<<"2. Generate 30 random numbers using LCG"<<endl;
  cout<<"3. Exit"<<endl;
}

//---------------------------------------------------------------------

double washerVolume(double outRad,double inRad, double height ){
  //function to calculate the volume of washerVol
  //pi(r2^2-r1^2)h
  return M_PI*(pow(outRad,2) - pow(inRad,2))*height;
}

//---------------------------------------------------------------------
double randlcg(int seed, int multiplier, int adder, int modul){
//function to calculate LCG random number
return ((multiplier*seed) + adder)%(modul);
}
//----------------------------------------------------------------------
