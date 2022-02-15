#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
class Employee {
	static Employee *emp;
	int empId;
	Employee() { }

	public:
	static Employee *createInstance() {
		if (!emp) {
		    mtx.lock();
		    if (!emp) {
        		emp = new Employee;
        		cout << "Instance created!" << endl;
		    }
		    mtx.unlock();
		}
		return emp;
	}
};

// Initialize pointer to zero so that it can be initialized in first call to createInstance
Employee *Employee::emp = 0;

int main() {
	// No-thread Version
    // Prints the "Instance Created!" when the below line runs
// 	Employee *emp1 = emp1->createInstance();
	// Prints nothing when the below line runs as one instance is already created
// 	Employee *emp2 = emp2->createInstance();

	// Thread Version, to be run after commenting the No-thread Version
	thread t1{[&] {
		Employee *emp = emp->createInstance();
	}};
	thread t2{[&] {
		Employee *emp = emp->createInstance();
	}};
	
	t1.join();
	t2.join();
	return 0;
}