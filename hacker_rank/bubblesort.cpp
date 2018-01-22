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

void swap (int elem1, int elem2, vector <int>& a, int& num_swap) {
    int temp = a[elem2];
    a[elem2] = a[elem1];
    a[elem1] = temp;
    num_swap++;
}

int main(){
    int n;
    int num_swap = 0;
    int k = 0;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - k; j++) {
            if (a[j] > a[j + 1]) {
                swap(j, j + 1, a, num_swap);
            }
        }
        k++;
    }
    cout << "Array is sorted in " << num_swap << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] << endl;
    return 0;
}
