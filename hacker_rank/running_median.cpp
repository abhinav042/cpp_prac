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
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue <int> min_vals;
    priority_queue <int, vector<int>, greater<int>> max_vals;
    float median = 0;
    float first_val;
    float second_val;
    int max_size = 0;
    int min_size = 0;
    for (int a_i = 0; a_i < n; a_i++) {
        
        cin >> a[a_i];
      
        if (a_i == 0) {
            
            median = (float)a[0];
            cout << setprecision(1) << fixed;
            cout << median << endl;
            first_val = a[0];
            
        } else if (a_i == 1) {
            
            median = ((float)a[0]+(float)a[1])/2;
            cout << setprecision(1) << fixed;
            cout << median << endl;
            second_val = a[1];
            
            if (first_val > second_val) {
                min_vals.push(second_val);
                max_vals.push(first_val);
            } else {
                
                max_vals.push(second_val);
                min_vals.push(first_val);
            }
            
        } else if (a_i > 1) {
            
            // initial push
            if (a[a_i] >= median) {
                
                max_vals.push(a[a_i]);
            } else {
                
                min_vals.push(a[a_i]);
            }
            
            // rearranging the sets
            max_size = max_vals.size();
            min_size = min_vals.size();
            if (max_size - min_size > 1) {
                
                min_vals.push(max_vals.top());
                
                max_vals.pop();
            } else if (min_size - max_size > 1) {
                
                max_vals.push(min_vals.top());
                
                min_vals.pop();
            }
            max_size = max_vals.size();
            min_size = min_vals.size();
            // setting the median
            if (max_size > min_size) {
                median = (float)max_vals.top();
            } else if (max_size < min_size) {
                median = (float)min_vals.top();
            } else if (max_size == min_size) {
                median = ((float)min_vals.top()+(float)max_vals.top())/2;
            }
            cout << setprecision(1) << fixed;
            cout << median << endl;
            
        }
        
    }
    
    return 0;
}