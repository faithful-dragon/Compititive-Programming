#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime)%24;
    }
};