//Xinxin Chen CSC 245
//Lab1
//1/11/2017

#include <iostream>
using namespace std;

double convert(double value);
	
int main (){
	double cel;
	cout << "Please enter a Celsius value: ";
	cin  >> cel;
		cout << cel << " degrees Celsius is " << convert(cel) << " degrees Fahrenheit." << endl;	
	return 0;
}

double convert (double cel){
	double fah = 1.8 * cel + 32.0; 	
	return fah;
}
