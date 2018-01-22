#include <bits/stdc++.h>
#include <utility> 

using namespace std;

void solve(vector <int> arr, int money) {
    // Complete this function
    int i = 0;
    unordered_multimap <int, int> indexes;
    for (auto cost : arr) {
        // cout << "index is : " << i << " val is : " << cost << endl;
        i++;
        indexes.insert(make_pair<int, int>((int)cost, (int)i));
    }
    for (auto& it : indexes) {
        // cout << "the key is : " << it.first << "the val is : " << it.second << endl;
        if (indexes.find(money - it.first) != indexes.end() && indexes.find(money - it.first)->second != it.second) {
            if (it.second > indexes.find(money - it.first)->second) {
                cout << indexes.find(money - it.first)->second << " " << it.second << endl;
            } else {
                cout << it.second << " " << indexes.find(money - it.first)->second << endl;
            }
            return;
        }
    }
    // cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}
