#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check_storage(string s1, string s2) {
    string s3;
    int len = s1.length();
    if (len == s2.length() && len > 0) {
        s3 = s1 + s1;
        if (s3.find(s2) != -1)
            return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "enter the string : ";
    cin >> s1;
    cout << "enter the other string : ";
    cin >> s2;
    if (check_storage(s1, s2))
        cout << "true";
    else
        cout << "false";
}