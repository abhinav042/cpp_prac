#include <iostream>
#include <algorithm>
#include <stack>
#include <vector> 

using namespace std; 

struct Interval {
    int start;
    int end;
};

struct comparator {
    bool operator() (const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }
};

stack <Interval> mergeIntervals(Interval* arr, int n) {
    stack <Interval> s;
    if (arr == nullptr)
        return s;
    sort(arr, arr + n, comparator());
    s.push(arr[0]);
    Interval top = s.top();
    
    for (int i = 1; i < n; i++) {
        if (top.end < arr[i].start) {
            s.push(arr[i]);
        } else if (top.end < arr[i].end) {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty()) {
        Interval temp = s.top();
        cout << temp.start << " " << temp.end << endl;
        s.pop();
    }
    return s;
}

int main() {
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7}, {20, 100} };
    int n = sizeof(arr)/sizeof(arr[0]);
    stack <Interval> s1 = mergeIntervals(arr, n);
    // while (!s1.empty()) {
    //     cout << s1.top().start << " " << s1.top().end << endl;
    //     s1.pop();
    // }
    return 0;
}