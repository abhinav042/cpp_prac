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

int get_region_size(vector<vector<int>>& grid, int row, int column, int row_length, int col_length) {
    int region_size = 1;
    if (row < 0 || row > row_length - 1 || column < 0 || column > col_length - 1 || grid[row][column] == 0) {
        return 0;
    }
    grid[row][column] = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = column - 1; c <= column + 1; c++) {
            region_size += get_region_size(grid, r, c, row_length, col_length);
        }
    }
    return region_size;
}

int get_biggest_region(vector< vector<int> > grid, int n, int m) {
    int max_size = 0;
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            if (grid[row][column] != 0) {
                int region_size = get_region_size(grid, row, column, n, m);
                if (region_size > max_size) {
                    max_size = region_size;
                }
            }
        }
    }
    return max_size;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid, n, m) << endl;
    return 0;
}
