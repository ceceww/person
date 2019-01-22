
#include <iostream>
#include <string>

#include "Tester.h"


using std::cout;
using std::endl;


int main(int argc, char* argv[]) {

	while (argc > 1) {
		switch (argv[--argc][0]) {
		case 'a':
		{
			Tester t;
			t.testCustomerConstrAndGet();
		}
		break;
		case 'b':
		{
			Tester t;
			t.testManagerConstrAndGet();
		}
		break;
		case 'c':
		{
			Tester t;
			t.testConsultantConstrAndGet();
		}
		break;
		case 'd':
		{
			Tester t;
			t.testCustomerType();
		}
		break;
		case 'e':
		{
			Tester t;
			t.testManagerType();
		}
		break;
		case 'f':
		{
			Tester t;
			t.testConsultantType();
		}
		break;
		case 'g':
		{
			Tester t;
			t.testCustomerToString();
		}
		break;
		case 'h':
		{
			Tester t;
			t.testManagerToString();
		}
		break;
		case 'i':
		{
			Tester t;
			t.testConsultantToString();
		}
		break;
		case 'j':
		{
			Tester t;
			t.testConsultantDestr();
		}
		break;
		case 'k':
		{
			Tester t;
			t.testIcreaseSalaryBy();
		}
		break;
		case 'l':
		{
			Tester t;
			t.testAddOrder();
		}
		break;
		default:
		{
			cout<<"Options are a -- l."<<endl;
		}
		break;
       	}
	}
	
	return 0;
}

