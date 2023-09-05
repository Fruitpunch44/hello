#include<iostream>
using namespace std;

class Car{
    public:
    string engineName;
    string tires;
    string model;

Car(string EngineName, string Tires, string Model){
engineName=EngineName;
tires=Tires;
model=Model;
}

};


   int main()
   {
    Car toyota("v8","4 wheels","paseo");
    cout<<toyota.engineName<<endl;

   }
 