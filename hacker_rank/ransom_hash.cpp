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

int number_needed(string a, string b) {
    int ans = 0;
    unordered_map <int, int> count;
    for (auto letter : a) {
        count[letter]++;
    }
    for (auto letter : b) {
        if (!count[letter])
            ans++;
        else if (count[letter]) {
            count[letter]--;
        }
    }
    for (auto itr : count) {
        if (itr.second > 0) {
            ans+=itr.second;
        }
    }
    return ans;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
