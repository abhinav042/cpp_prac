#include <iostream>
#include <vector>

using namespace std;

class Employee {
    private:
        bool status;
        int rank;
    public:
        Employee() {
            status = true;
        }
        bool get_status() {
            return status;
        }
        int get_rank() {
            return rank;
        }

};

class Respondent: public Employee {
    public:

};

class Manager: public Employee {
    public:
};

class Director: public Employee {
    public:
};

class CallHandler {
    private:
        vector < vector<Employee> > employee_list;
        vector < vector<Call> > call_list;
        
    public:
        CallHandler() {

        }
};

class Call {

}; 

int main() {
    CallHandler call_handler;
    return 0;
}