//Shishir Khanal
//CS 4499
//Purpose: Create Mean of LCG
//         Create bins for lCG

#include <iostream>
#include <vector>
#include <string>
using namespace std;


double randlcg(int, int);
double meanCalc(int, int, int);
int binCreate(int, int, int);
void binTally(int,int);
int periodcalc(int, int);

int main(){
int modul =2^24;
int seed = 100001;
cout<<"What would you like to do?"<<endl;
cout<<"1. Find the mean of 100 random numbers"<<endl;
cout<<"2. Find the mean of 10,000 random numbers"<<endl;
cout<<"3. Find the mean of 1,000,000 random numbers"<<endl;
cout<<"4. Find the mean of 100,000,000 random numbers"<<endl;
cout<<"5. Create and Tally map bin for 100 random numbers"<<endl;
cout<<"6. Calculate Period of LCG"<<endl;
cout<<"7. Exit"<<endl;
int option;
cin>>option;
if (option==1){
  cout<<"Mean of 100 Random Numbers are: "<<meanCalc(100, modul, seed)<<endl;
  }
if (option==2){
  cout<<"Mean of 10,000 Random Numbers are: "<<meanCalc(10000, modul, seed)<<endl;
  }
if (option==3){
  cout<<"Mean of 1,000,000 Random Numbers are: "<<meanCalc(1000000, modul, seed)<<endl;
  }
if (option==4){
  cout<<"Mean of 100,000,000 Random Numbers are: "<<meanCalc(100000000, modul, seed)<<endl;
  }
if (option==5){
 binTally(seed, modul);
}
if (option==6){
  cout<<"The Period of LCG is "<<periodcalc(seed, modul)<<endl;
}
if (option==7){
  exit(EXIT_SUCCESS);
}
  return 0;
}

double randlcg(int seed,int modul){
//function to calculate LCG random number
int multiplier =61.0;
int adder = 1.0;
return (((multiplier*seed) + adder)%(modul));
}

double meanCalc(int itemNum, int modul, int seed){
  double randNum = 0;
  double sum = 0;
  double normRand = 0.0;
  for(int i = 0; i<itemNum; i++){
    randNum = randlcg(seed, modul);
    normRand = randNum/modul;
    seed = randNum;
    sum +=normRand;
  }
  return sum/itemNum;
}
int binCreate(int seed, int modul, int randNums){
  int binSize = 100;
  vector<int> bins(binSize,0);
  int count =0;
double rand = 0;
for (int i = 0; i<randNums ; i++){
  double Num = randlcg(seed, modul);
  double rand = Num/modul;
  seed = Num;
  bins.at(static_cast<int>(rand*binSize))++;
  if (bins.at(i)!=0) count++;
}
cout<<count;
return count;
}

void binTally(int seed, int modul){
  cout<<"For 100 random numbers "<< binCreate(seed, modul,100)<<" bins were tallied"<<endl;
  cout<<"For 10,000 random numbers "<< binCreate(seed, modul,10000)<<" bins were tallied"<<endl;
  cout<<"For 1,000,000 random numbers "<< binCreate(seed, modul,1000000)<<" bins were tallied"<<endl;
  cout<<"For 100,000,000 random numbers "<< binCreate(seed, modul,100000000)<<" bins were tallied"<<endl;
}

int periodcalc(int seed, int modul){
  double FirstRand = randlcg(seed, modul);
  int count = 0;
    double seed1 = FirstRand;
  while(seed!=FirstRand){
  seed = seed1;
  seed = randlcg(seed, modul);
    count++;
  }
  return count;
}
