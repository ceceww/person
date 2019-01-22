#ifndef TESTER_H_
#define TESTER_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Tester {
	
public:
	Tester();
	~Tester();

	void testCustomerConstrAndGet();
	void testManagerConstrAndGet();
	void testConsultantConstrAndGet();

	void testCustomerType();
	void testManagerType();
	void testConsultantType();
	
	void testCustomerToString();
	void testManagerToString();
	void testConsultantToString();
	
	void testConsultantDestr();
	void testIcreaseSalaryBy();
	void testAddOrder();
		
	
private:
	
	std::string generateName_();
	double generateSalary_();
	int* generateOrders();

	unsigned int generateCustomerData_(vector<string>& names, vector<const char*>& names_c, vector<unsigned int>& ids);
	unsigned int generateEmployeeData_(vector<string>& names, vector<const char*>& names_c, vector<double>& salarys);

	void errorOut_(const std::string& errMsg, unsigned int errBit);
	void passOut_(const std::string& passMsg);

	char error_;
	std::string funcname_;

	static const unsigned int NAME_LENGTH = 10;
	static const unsigned int MAX_ID = 1000000;
	static const unsigned int NUMBER_OBJECTS = 100;
	static const unsigned int NUMBER_ORDERS = 10;
	static const unsigned int NUMBER_SHARING = 5;
	static const unsigned int MIN_SALARY = 20000;
	static const unsigned int MAX_SALARY = 100000;

};

#endif /* TESTER_H_ */
