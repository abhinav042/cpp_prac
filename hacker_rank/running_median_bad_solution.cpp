/*

BRUTE FORCE 

BAD SOLUTION 

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
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    multiset <int> running_median;
    multiset <int>::iterator itr;
    multiset <int>::iterator itr2;
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
        running_median.insert(a[a_i]);
        // for (auto itr_temp : running_median) cout << itr_temp << " ";
        // cout << endl;
        // cout << "a_ith value is : " << a_i << endl;
        itr = running_median.begin();
        // itr2 = running_median.begin();
        advance(itr, floor(a_i/2));
        if ((a_i + 1)%2 == 0) {
            float val1 = *itr;
            // cout << "val1 is : "<< val1 << endl;
            advance(itr, 1);
            float val2 = *itr;
            // cout << "val2 is : "<< val2 << endl;
            float median = (val1 + val2)/2;
            cout << setprecision(1) << fixed;
            cout << median << endl;
        } else {
            cout << setprecision(1) << fixed;
            cout << (float)*itr << endl;
        }
    }
    return 0;
}
