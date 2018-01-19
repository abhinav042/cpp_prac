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

bool is_matched(char ch1, char ch2) {
    if ((ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']'))
        return true;
    else 
        return false;
}

bool is_balanced(string expression) {
    stack <char> s;
    for (auto letter : expression) {
        if (letter == '{' || letter == '(' || letter == '[') {
            s.push(letter);
        }
        else {
            // cout << "letter is" << letter << " top stack is " << s.top() << endl;
            if (!s.empty() && is_matched(s.top(), letter))
                s.pop();
            else 
                return false;
        }
        // cout << s.top() << endl;
    }
    if (s.empty())
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
