#include "Person.h"
#include <iostream>

using std::string;

// Create a new Person with a name
Person::Person(const char* name){
	personName=name;
}

// Create a new Person with a name
Person::Person(const std::string& name){
	personName=name;
}

// Same as default destructor
Person::~Person(){
}

// Get the name of this person
std::string Person::name() const{
	return personName;
}

// Virtual functions in this base class
std::string Person::toString() const{
	return this->personName;
}

std::string Person::type() const{
	return "Person";
}

// Returns the string representation of this Person p
// The toString() function called depends on type of Person
std::ostream& operator<<(std::ostream& o, const Person& p){
	o << p.toString();
	return o;
}

// Create a new named Person of type Customer
// Assign him or her a customer ID
Customer::Customer(const char* name, unsigned int customerId):Person(name){
	cId = customerId;
}

// Create a new named Person of type Customer
// Assign him or her a customer ID
Customer::Customer(const std::string& name, unsigned int customerId):Person(name){
	cId = customerId;
}

Customer::~Customer(){
	// Release dynamically allocated memory
	delete[] orders;
}

// Add a new order number to this customer's array of order numbers
// Resizes the order array to accommodate one more order
void Customer::addOrder(unsigned int order){
	// STEP 1: RESIZE ARRAY ORDER
	// Allocate memory for array of orders that can hold one more
	unsigned int * temp = new unsigned int[s_orders+1];
	// Copy contents of old array into the new one
	for (int i=0; i<s_orders; i++){
		temp[i] = this->orders[i];
	}
	// Free memory
	delete[] this->orders;
	// Point order to new memory location with space for one extra order number
	this->orders = temp;
	// Finished with temp so make it point to nullptr
	temp = nullptr;
	// Create pointer to  update size
	int * s_orders_ptr = &this->s_orders;
	*s_orders_ptr = s_orders + 1;
	s_orders_ptr = nullptr;

	//STEP 2: ADD ORDER TO RESIZED ARRAY
	if (s_orders>0){
		this->orders[this->s_orders-1] = order;
	}
}

// Return the order number at position i in the order array
unsigned int Customer::getOrder(unsigned int i){
	unsigned int order = 0;
	if (i>this->s_orders-1){
		return order;
	}
	else{
		order = this->orders[i];
	}
	return order;
}

// Get this customer's ID
unsigned int Customer::id() const{
	return cId;
}

// Override virtual function
std::string Customer::toString() const{
	std::string orders_str = "";
	for (int i=0;i<s_orders;i++){
		if ((i == 0) && (s_orders == 1)) {
			orders_str.append(", " + std::to_string(orders[i]));
		}
		else if (i==0) {
			orders_str.append(", " + std::to_string(orders[i]) + ", ");
		}
		else if (i == s_orders-1){
			orders_str.append(std::to_string(orders[i]));
		}
		else {
			orders_str.append(std::to_string(orders[i]) + ", ");
		}
	}
	std::string customerString = "[" + personName + ", " + std::to_string(cId);
	customerString = customerString + orders_str;
	customerString = customerString + "]";
	return customerString;
}

// Override virtual function
std::string Customer::type() const{
	return "Customer";
}

// Create a new named Person of type Employee
// Initialise his or her salary
Employee::Employee(const char* name, double salary):Person(name){
	sal = salary;
}

// Create a new named Person of type Employee
// Initialise his or her salary
Employee::Employee(const std::string& name, double salary):Person(name){
	sal = salary;
}

// Same as default destructor
Employee::~Employee(){
}

void Employee::increaseSalaryBy(double amount){
	// Create pointer to sal
	double* sal_ptr = &sal;
	// Increase by amount
	*sal_ptr = sal + amount;
}

// Get this employee's salary
double Employee::salary()const{
	return sal;
}

// Override virtual function
std::string Employee::toString() const{
	return "[" + personName + ", earns: " + std::to_string(sal) + "]";
}

// Override virtual function
std::string Employee::type() const{
	return "Employee";
}

// Create a new Employee of type Manager
// Initialisation of name and salary done in creation of Employee
Manager::Manager(const char* name, double salary):Employee(name,salary){
}

// Create a new Employee of type Manager
// Initialisation of name and salary done in creation of Employee
Manager::Manager(const std::string& name, double salary):Employee(name,salary){
}

// Same as default destructor
Manager::~Manager(){
}

// Override virtual function
std::string Manager::toString() const{
	return "[" + personName + ", earns: " + std::to_string(sal) + "]";
}

// Override virtual function
std::string Manager::type() const{
	return "Manager";
}

// Create a new Employee of type Consultant
// Initialisation of name and salary done in creation of Employee
// Manager is set in a separate function
Consultant::Consultant(const char* name, double salary):Employee(name,salary){
	manager = nullptr;	
}

// Create a new Employee of type Consultant
// Initialisation of name and salary done in creation of Employee
// Manager is set in a separate function
Consultant::Consultant(const std::string& name, double salary):Employee(name,salary){
	manager = nullptr;
}

Consultant::~Consultant(){
	// Free dynamic memory
	delete manager;
}

// Assign manager to this consultant
void Consultant::setManager(Manager* manager){
	this->manager = manager;
}

// Return the name of this consultant's manager
std::string Consultant::getManagerName() const{
	std::string managerName = this->manager->name();
	return managerName;
}

// Override virtual function
std::string Consultant::toString() const {
	return "[" + this->personName + ", earns: " + std::to_string(sal) + ", manager: " + this->getManagerName() + "]";
}

// Override virtual function
std::string Consultant::type() const {
	return "Consultant";
}
