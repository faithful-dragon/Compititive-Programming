#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--;
            char character = 'A' + (columnNumber % 26);
            result = character + result;
            columnNumber /= 26;
        }
        return result;
    }
};