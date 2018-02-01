#include <iostream>
#include <string>

using namespace std;

int main() {
    string reverse = "hello world reverse";
    char temp;
    for (int i = 0, j = reverse.length() - 1; i!=j; i++, j--) {
        temp = reverse[i];
        reverse[i] = reverse[j];
        reverse[j] = temp;
    }
    cout << reverse << endl;
}