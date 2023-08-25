#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int total_step = 0;
        int step = 0;
        int water = capacity;

        for(int c:plants){
            cout<<c<<" "<<water<<" "<<total_step<<endl;
            if(water>=c){
                step++;
                water -= c;
            }
            else{
                total_step += 2*step;
                step++;
                water = capacity-c;
            }
            cout<<c<<" "<<water<<" "<<total_step<<endl;
            cout<<endl;
        }

        return total_step + step;
    }
};