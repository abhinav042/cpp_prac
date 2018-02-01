#include <iostream>
#include <vector>

using namespace std;

void SieveOfEratosthenes (int n) {
    vector <bool> num_list(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        if (num_list[i]) {
            for (int j = i*2; j <= n; j += i) {
                cout << "j val is : " << j << endl;
                num_list[j] = false;
            }
        }
    }
    int num_index = 0;
    for (auto itr : num_list) {
        if (itr) cout << num_index << " " ;
        num_index++;
    }
}

int main() {
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}