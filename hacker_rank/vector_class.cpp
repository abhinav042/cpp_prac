#include <iostream>

using namespace std;

template <class T> 
class Vector_class {
    private:
        int total_elem;
        int max_size;
        T* arr;
    public:
        // Vector_class();
        T& operator [] (int i);
        void push_vector(const T& item);
        void reserve(int reserve_amount);
};

// template <class T>
// Vector_class<T>::Vector_class() {
//     // T* arr = nullptr;
//     total_elem = 0;
//     max_size = 1;
// }

template <class T>
T& Vector_class<T>::operator [ ] (int i) {
    return arr[i];
}

template <class T>
void Vector_class<T>::reserve(int reserve_amount) {

    T* new_array = new T[reserve_amount];
    if (reserve_amount != 1) {
        for (int i = 0; i < total_elem; i++) {
            new_array[i] = arr[i];
        }
        delete [] arr;
    }

    arr = new_array;
    // update the capacities
    max_size = reserve_amount;
}

template <class T>
void Vector_class<T>::push_vector(const T& item) {
    if (total_elem == max_size) {
        if (total_elem == 0) {
            reserve(1);
            cout << "im going here" << endl;
        } else {
            cout << "rest of the time here..." << endl;
            reserve(2 * max_size);
        }
    }
    arr[total_elem] = item;
    total_elem++;
}

int main() {
    Vector_class<int> vec;
    vec.push_vector(1);
    vec.push_vector(2);
    vec.push_vector(3);
    cout << vec[1] << endl;
    return 0;
}