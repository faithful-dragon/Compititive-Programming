#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>>v;
    SubrectangleQueries(vector<vector<int>>& rec) {
        v=rec;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                v[i][j]=newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return v[row][col];
    }
};