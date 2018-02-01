#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    if (n == 0) {
        return 0;
    }
    int first_num = 0;
    int second_num = 1;
    int fib_num;
    for (int i = 2; i < n; i++) {
        fib_num = first_num + second_num;
        first_num = second_num;
        second_num = fib_num;
    }
    return first_num + second_num;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
