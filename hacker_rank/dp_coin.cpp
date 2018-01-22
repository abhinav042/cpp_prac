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

long long make_change(vector<int> coins, int money, unordered_map <string, long>& cache, int index = 0) {
    string key;
    if (money == 0) {
        return 1;
    }
    if (index >= coins.size()) {
        return 0;
    }
    long ways = 0;
    int coin_val = coins[index];
    key = to_string(money) + '-' + to_string(coin_val);
    // cout << "the key is : " << key << endl;
    if (cache.find(key) != cache.end()) {
        // cout << "the cache is being entered..." << endl;
        return cache[key];
    }
    for (int i = 0; i * coin_val <= money; i++) {
        // cout << "weee i went here..." << endl;
        // cout << endl;
        int remaining_money = money - i * coin_val;
        ways += make_change (coins, remaining_money, cache, index + 1);
    }
    cache[key] = ways;
    auto itr = cache.find(key);
    // if (itr != cache.end()) {
    //     cout << "*itr" << endl;
    // }
    return ways;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    unordered_map <string, long> cache;
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n, cache) << endl;
    return 0;
}
