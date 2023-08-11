#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(vector<int>&v:image){
            reverse(v.begin(),v.end());
        }
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[0].size();j++){
                if(image[i][j]==0)image[i][j]=1;
                else image[i][j]=0;
            }
        }
        return image;
    }
};