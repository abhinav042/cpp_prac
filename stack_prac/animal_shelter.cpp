#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Animal {
private:
    int order;
protected:
    int status;
    string name;
public:
    void set_order(int order) {
        this->order = order;
    }
    int get_order() {
        return order;
    }
    bool is_older(Animal a) {
        if (a.get_order() > order) return true;
        else return false;
    }
};

class AnimalQueue {
    queue <Dog> list_dog;
    queue <Cat> list_cat;

    Animal dequeueAny() {
        if (list_dog.front().get_order() < list_cat.front().get_order()) {
            Dog a = list_dog.front();
            list_dog.pop();
            return a;
        } else {
            Cat a = list_cat.front();
            list_cat.pop();
            return a;
        }
    }

    void dequeueDog() {
        list_dog.pop();
    }

    void dequeueCat() {
        list_cat.pop();
    }

};

class Dog : public Animal {
    Dog(string name) {
        this->name = name;
        status = 1;
    }
};

class Cat : public Animal {
    Cat(string name) {
        this->name = name;
        status = 2;
    }
};

int main() {
    return 0;
}