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

void merge_halves(long long inversions, vector <int> a, vector<int>& temp, int left_start, int right_end) {
    int left_end = (left_start + right_end) / 2;
    int right_start = left_end + 1;
    int temp_size = right_end + left_start - 1;
    int i, j, index;
    for (i = left_start, j = right_start; i <= left_end && j <= right_end; i++, j++) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
            index++;
        } else {
            inversions++;
            temp.push_back(a[j]);
            j++;
            index++;
        }
    }
    if (j == right_end) {
        for (int k = i; k <= left_end; k++) {
            temp[index] = a[k];
        }
    } else {
        for (int k = j; k <= right_end; k++) {
            temp[index] = a[k];
        }
    }
}

void merge_sort(long long inversions, vector <int> a, vector <int>& temp, int left_start, int right_end) {
    if (left_start >= right_end) {
        return;
    } else {
        int middle = (left_start + right_end) / 2;
        merge_sort(inversions, a, temp, left_start, middle);
        merge_sort(inversions, a, temp, middle + 1, right_end);
        merge_halves(inversions, a, temp, left_start, right_end);
    }
}

long long count_inversions(vector<int> a) {
    vector <int> temp;
    long long inversions = 0;
    merge_sort(inversions, a, temp, 0, a.size() - 1);
    for (auto num : temp) {
        cout << num << " ";
    }
    return inversions;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
