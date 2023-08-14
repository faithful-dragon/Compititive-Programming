#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double Kelvin,Fahrenheit;
        Kelvin = celsius + 273.15;
        Fahrenheit = celsius * 1.80 + 32.00;
        return {Kelvin,Fahrenheit};
    }
};