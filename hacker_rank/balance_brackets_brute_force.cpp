/* 

BRUTE FORCE SOLUTION WHICH DOESNT WORK PROPERLY 

*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    int unbalanced = 0;
    for (int i = 0; i < expression.size(); i++) {
        char bracket = expression[i];
        if (bracket == '{') {
            unbalanced++;
            if (i!=expression.size() && (expression[i+1]!='}' || expression[i+1]!='{' || expression[i+1]!='(' || expression[i+1]!='['))
                return false;
            else if (i == expression.size())
                return false;
            else if (i!=expression.size() && expression[i+1]=='}')
                unbalanced--; 
        }
        if (bracket == '(') {
            unbalanced++;
            if (i != expression.size() && (expression[i+1]!=')' || expression[i+1]!='{' || expression[i+1]!='[' || expression[i+1]!='('))
                return false;
            else if (i == expression.size())
                return false;
            else if (i!=expression.size() && expression[i+1]==')')
                unbalanced--; 
        }
        if (bracket == '[') {
            unbalanced++;
            if (i != expression.size() && (expression[i+1]!=']' || expression[i+1]!='{' || expression[i+1]!='[' || expression[i+1]!='('))
                return false;
            else if (i == expression.size())
                return false;
            else if (i!=expression.size() && expression[i+1]==']')
                unbalanced--;
        }
    }
    if (unbalanced == 0)
        return true;
    else 
        return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
