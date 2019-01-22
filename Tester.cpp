#include <stdlib.h>
#include <iostream>
#include <utility>
#include <sstream> 
#include <iomanip>

#include "Tester.h"
#include "Person.h"

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

Tester::Tester() : error_(false), funcname_("") {
	unsigned int val(time(0)*rand());
	srand(val);
}

Tester::~Tester() {
}


void Tester::testCustomerConstrAndGet(){
    funcname_ = "testCustomerConstrAndGet";

    vector<string> names;
    vector<const char*> names_c;
    vector<unsigned int> ids;


    unsigned int number = generateCustomerData_(names, names_c,ids);

    bool fail=false;
    for(int i =0; i < number && !fail ;++i){
        

        Customer c1(names[i],ids[i]);
        string name1 = c1.name();
        unsigned int id1 = c1.id();

        if(name1 != names[i]){
            errorOut_("Wrong name when using string consructor.",1);
            fail=true;
        }
        if(id1 != ids[i]){
            errorOut_("Wrong id when using string consructor.",2);
            fail=true;
        }

        
        Customer c2(names_c[i],ids[i]);
        string name2 = c2.name();
        unsigned int id2 = c2.id();

        if(name2 != names[i]){
            errorOut_("Wrong name when using char* consructor.",3);
            fail=true;
        }
        if(id2 != ids[i]){
            errorOut_("Wrong id when using char* consructor.",4);
            fail=true;
        }
        
        unsigned int o1 =  c1.getOrder(rand()%NUMBER_ORDERS);
        unsigned int o2 =  c2.getOrder(rand()%NUMBER_ORDERS);

        if(o1 != 0 || o2 !=0){
            errorOut_("Positive order number for empty order list.",5);
            fail=true;
        }
        
    }

    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested the constructors and getters of class Customer.");
}

void Tester::testManagerConstrAndGet(){
    funcname_ = "testManagerConstrAndGet";

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c, salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
        
        Manager m1(names[i],salaries[i]);
        string name1 = m1.name();
        double salary1 = m1.salary();

        if(name1 != names[i]){
            errorOut_("Wrong name when using string consructor.",1);
            fail=true;
        }
        if(salary1 != salaries[i]){
            errorOut_("Wrong salary when using string consructor.",2);
            fail=true;
        }

        
        Manager m2(names_c[i],salaries[i]);
        string name2 = m2.name();
        double salary2 = m2.salary();

        if(name2 != names[i]){
            errorOut_("Wrong name when using char* consructor.",3);
            fail=true;
        }
        if(salary2 != salaries[i]){
            errorOut_("Wrong salary when using char* consructor.",4);
            fail=true;
        }
    }
    

    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested the constructors and getters of class Manager.");
}

void Tester::testConsultantConstrAndGet(){
    funcname_ = "testConsultantConstrAndGet";

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;
 
    unsigned int number = generateEmployeeData_(names, names_c, salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
        
        Consultant c1(names[i],salaries[i]);

        string name1 = c1.name();
        double salary1 = c1.salary();
        
        string managerName1 = c1.getManagerName();

        if(name1 != names[i]){
            errorOut_("Wrong name when using string consructor.",1);
            fail=true;
        }
        if(salary1 != salaries[i]){
            errorOut_("Wrong salary when using string consructor.",2);
            fail=true;
        }
        if(managerName1 != ""){
            errorOut_("Wrong manager name when using string consructor.",3);
            fail=true;
        }

        
        Consultant c2(names_c[i],salaries[i]);
        string name2 = c2.name();
        double salary2 = c2.salary();
        string managerName2 = c2.getManagerName();

        if(name2 != names[i]){
            errorOut_("Wrong name when using char* consructor.",4);
            fail=true;
        }
        if(salary2 != salaries[i]){
            errorOut_("Wrong salary when using char* consructor.",5);
            fail=true;
        }
        if(managerName2 != ""){
            errorOut_("Wrong manager name when using char* consructor.",6);
            fail=true;
        }

        
        string managerName = generateName_();
        double managerSalary = generateSalary_();
        Manager *mp = new Manager(managerName,managerSalary);

        c1.setManager(mp);
        managerName1 = c1.getManagerName();
        if(managerName1 != managerName){
            errorOut_("Wrong manager name.",7);
            fail=true;
        }

        delete mp;
        mp=nullptr;
        
    }


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested the constructors and getters of class Consultant.");
}

void Tester::testCustomerType(){
    funcname_ = "testCustomerType";

    vector<string> names;
    vector<const char*> names_c;
    vector<unsigned int> ids;

    unsigned int number = generateCustomerData_(names, names_c,ids);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
        
        Customer c(names[i],ids[i]);
        string type = c.type();
        if(type!="Customer"){
            errorOut_("Wrong type for Customer object.",1);
            fail=true;
        }

        Person *pp = new Customer(names[i],ids[i]);
        type = pp->type();
        if(type!="Customer"){
            errorOut_("Wrong type for Customer object.",2);
            fail=true;
        }
        delete pp;  
    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function type for class Customer.");
}

void Tester::testManagerType(){
    funcname_ = "testManagerType";

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c,salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
        
        Manager m(names[i],salaries[i]);
        string type = m.type();
        if(type!="Manager"){
            errorOut_("Wrong type for Manager object.",1);
            fail=true;
        }

        Person *pp = new Manager(names[i],salaries[i]);
        type = pp->type();
        if(type!="Manager"){
            errorOut_("Wrong type for Manager object.",2);
            fail=true;
        }
        delete pp;

        Employee *ep = new Manager(names[i],salaries[i]);
        type = ep->type();
        if(type!="Manager"){
            errorOut_("Wrong type for Manager object.",3);
            fail=true;
        }
        delete ep;

    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function type for class Manager.");
}

void Tester::testConsultantType(){
    funcname_ = "testConsultantType";
    
    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c,salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
        
        Consultant c(names[i],salaries[i]);
        string type = c.type();
        if(type!="Consultant"){
            errorOut_("Wrong type for Consultant object.",1);
            fail=true;
        }

        Person *pp = new Consultant(names[i],salaries[i]);
        type = pp->type();
        if(type!="Consultant"){
            errorOut_("Wrong type for Consultant object.",2);
            fail=true;
        }
        delete pp;

        Employee *ep = new Consultant(names[i],salaries[i]);
        type = ep->type();
        if(type!="Consultant"){
            errorOut_("Wrong type for Consultant object.",3);
            fail=true;
        }
        delete ep;
    
    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function type for class Consultant.");
}

void Tester::testCustomerToString(){
    funcname_ = "testCustomerToString";

    vector<string> names;
    vector<const char*> names_c;
    vector<unsigned int> ids;

    unsigned int number = generateCustomerData_(names, names_c,ids);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){

        stringstream ss_no_order;
        ss_no_order<<"["<<names[i]<<", "<<ids[i]<<"]";
        string no_order = ss_no_order.str();

        Customer c(names[i],ids[i]);
        string str = c.toString();
        if(str!=no_order){
            errorOut_("Wrong string Customer object.",1);
            fail=true;
        }

        Person *pp = new Customer(names[i],ids[i]);
        str = pp->toString();
        if(str!=no_order){
            errorOut_("Wrong string for Customer object.",2);
            fail=true;
        }
      
        int num_orders = rand()%NUMBER_ORDERS +1;
        stringstream ss_orders;
        ss_orders<<"["<<names[i]<<", "<<ids[i];
        for(int i=0; i < num_orders; ++i){
            unsigned int order = rand() % 1000;
            if(order > 0)
                ss_orders<<", "<<order;
            c.addOrder(order);
            (dynamic_cast<Customer*>(pp))->addOrder(order);        
        }
        ss_orders<<"]";
        string with_orders = ss_orders.str();

        str = c.toString();
        if(str!=with_orders){
            errorOut_("Wrong string Customer object.",3);
            fail=true;
        }


        str = pp->toString();
        if(str!=with_orders){
            errorOut_("Wrong string for Customer object.",4);
            fail=true;
        }        

        delete pp;  
    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function toString for class Customer.");
}

void Tester::testManagerToString(){
    funcname_ = "testManagerToString";

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c,salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){

        stringstream ss;
        ss<<"["<<names[i]<<", earns: "<<std::fixed << std::setprecision(2)
        <<salaries[i]<<"]";
        string str = ss.str();

        Manager m(names[i],salaries[i]);
        string mstr = m.toString();
        if(mstr!=str){
            errorOut_("Wrong string for Manager object.",1);
            fail=true;
        }

        Person *pp = new Manager(names[i],salaries[i]);
        mstr = pp->toString();
        if(mstr!=str){
            errorOut_("Wrong string for Manager object.",2);
            fail=true;
        }
        delete pp;

        Employee *ep = new Manager(names[i],salaries[i]);
        mstr = ep->toString();
        if(mstr!=str){
            errorOut_("Wrong string for Manager object.",3);
            fail=true;
        }
        delete ep;
    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function toString for class Manager.");
}

void Tester::testConsultantToString(){
    funcname_ = "testConsultantToString";

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c,salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){

        stringstream ss;
        ss<<"["<<names[i]<<", earns: "<<std::fixed << std::setprecision(2)
        <<salaries[i]<<"]";
        string str = ss.str();

        string managerName = generateName_();
        double managerSalary = generateSalary_();
        
        stringstream ss_with_manager;
        ss_with_manager<<"["<<names[i]<<", earns: "<<std::fixed << std::setprecision(2)
        <<salaries[i]<<", manager: "<<managerName<<"]";
        string str_with_manager = ss_with_manager.str();


        Consultant c(names[i],salaries[i]);
        string no_manager = c.toString();
        if(no_manager != str){
            errorOut_("Wrong string for Consultant object.",1);
            fail=true;
        }
        Manager *mp = new Manager(managerName,managerSalary);
        c.setManager(mp);
        string with_manager = c.toString();
        if(with_manager != str_with_manager){
            errorOut_("Wrong string for Consultant object.",2);
            fail=true;
        }
        delete mp;
        mp=nullptr;

        Person *pp = new Consultant(names[i],salaries[i]);
        no_manager = pp->toString();
        if(no_manager != str){
            errorOut_("Wrong string for Consultant object.",3);
            fail=true;
        }
        mp = new Manager(managerName,managerSalary);
        (dynamic_cast<Consultant*>(pp))->setManager(mp);
        with_manager = pp->toString();
        if(with_manager!=str_with_manager){
            errorOut_("Wrong string for Consultant object.",4);
            fail=true;
        }
        delete pp;
        delete mp;
        mp=nullptr;

        Employee *ep = new Consultant(names[i],salaries[i]);
        no_manager = ep->toString();
        if(no_manager!=str){
            errorOut_("Wrong string for Consultant object.",5);
            fail=true;
        }
        mp = new Manager(managerName,managerSalary);
        (dynamic_cast<Consultant*>(ep))->setManager(mp);
        with_manager = ep->toString();
        if(with_manager!=str_with_manager){
            errorOut_("Wrong string for Consultant object.",6);
            fail=true;
        }
        delete ep;
        delete mp;
        mp=nullptr;
    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function toString for class Consultant.");
}

void Tester::testConsultantDestr(){
    funcname_ = "testConsultantDestr";

    Manager *mp = new Manager(generateName_(),generateSalary_());

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c,salaries);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
        Consultant c(names[i],salaries[i]);
        c.setManager(mp);

        Consultant* cp = new Consultant(names[i],salaries[i]);
        cp->setManager(mp);

        delete cp;
        cp=nullptr;
    } 

    delete mp;


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested the destructor of class Consultant.");
}

void Tester::testIcreaseSalaryBy(){
    funcname_ = "testIncreaseSalaryBy";

    vector<string> names;
    vector<const char*> names_c;
    vector<double> salaries;

    unsigned int number = generateEmployeeData_(names, names_c,salaries);


    bool fail=false;
    for(int i =0; i < number && !fail;++i){

        double inc = generateSalary_();
        double dec =  0-inc;

        Manager m1(names[i],salaries[i]);
        Person *pp1 = new Manager(names[i],salaries[i]);
        Employee *ep1 = new Manager(names[i],salaries[i]);
        
        m1.increaseSalaryBy(dec);
        (dynamic_cast<Manager*>(pp1))->increaseSalaryBy(dec);
        ep1->increaseSalaryBy(dec);

        if(m1.salary()!=salaries[i] || (dynamic_cast<Manager*>(pp1))->salary()!=salaries[i] || ep1->salary()!=salaries[i]){
            errorOut_("Changed salary of Manager by negative amount.",1);
            fail=true;           
        }

        Manager m2(names[i],salaries[i]);
        Person *pp2 = new Manager(names[i],salaries[i]);
        Employee *ep2 = new Manager(names[i],salaries[i]);
        
        m2.increaseSalaryBy(inc);
        (dynamic_cast<Manager*>(pp2))->increaseSalaryBy(inc);
        ep2->increaseSalaryBy(inc);        

        if(m2.salary() != salaries[i] + inc || 
           (dynamic_cast<Manager*>(pp2))->salary() != salaries[i] + inc || 
           ep2->salary() != salaries[i]+inc){
            errorOut_("Did not correctly increase salary of Manager.",2);
            fail=true;           
        }     
        
        Consultant c1(names[i],salaries[i]);
        Person *pp3 = new Consultant(names[i],salaries[i]);
        Employee *ep3 = new Consultant(names[i],salaries[i]);
        
        c1.increaseSalaryBy(dec);
        (dynamic_cast<Consultant*>(pp3))->increaseSalaryBy(dec);
        ep3->increaseSalaryBy(dec);

        if(c1.salary()!=salaries[i] || (dynamic_cast<Consultant*>(pp3))->salary()!=salaries[i] || ep3->salary()!=salaries[i]){
            errorOut_("Changed salary of Consultant by negative amount.",3);
            fail=true;           
        }

        Consultant c2(names[i],salaries[i]);
        Person *pp4 = new Consultant(names[i],salaries[i]);
        Employee *ep4 = new Consultant(names[i],salaries[i]);
        
        c2.increaseSalaryBy(inc);
        (dynamic_cast<Consultant*>(pp4))->increaseSalaryBy(inc);
        ep4->increaseSalaryBy(inc);        

        if(c2.salary()!=salaries[i] + inc || 
           (dynamic_cast<Consultant*>(pp4))->salary()!=salaries[i] + inc || 
           ep4->salary()!=salaries[i]+inc){
            errorOut_("Did not correctly increase salary of Consultant.",4);
            fail=true;           
        }     
        delete pp1;
        delete pp2;
        delete pp3;
        delete pp4;
        delete ep1;
        delete ep2;
        delete ep3;
        delete ep4;

    }


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function icreaseSalaryBy.");
}

void Tester::testAddOrder(){
    funcname_ = "testAddOrder";

    vector<string> names;
    vector<const char*> names_c;
    vector<unsigned int> ids;

    unsigned int number = generateCustomerData_(names, names_c,ids);

    bool fail=false;
    for(int i =0; i < number && !fail;++i){
             
        Customer c(names[i],ids[i]);
        int index = 0;
        int num_orders = rand()%NUMBER_ORDERS +2;
        for(int i=0; i < num_orders && !fail; ++i){

            unsigned int order = rand() % 1000;
            if(i==0)
                order=0;

            c.addOrder(order);    

            if(order > 0){
                if(c.getOrder(index)!=order){
                    errorOut_("Wrong order number.",1);
                    fail=true;
                }
                index++;
            }            
        }

        for(int i=0; i < index && !fail; ++i){
            if(c.getOrder(i)==0){
                errorOut_("Order with id 0.",2);
                fail=true;
            }
        }
    } 


    for(int i =0; i < number;++i){
        delete [] names_c[i];
    }

    passOut_("Tested function addOrder.");
}




string Tester::generateName_() {
    static const char caps[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const char low[] =
        "abcdefghijklmnopqrstuvwxyz";

    string fname = "";
    string sname = "";
    unsigned int flength=rand() % NAME_LENGTH + 2;
    unsigned int slength=rand() % NAME_LENGTH + 2;
    
    fname += caps[rand() % (sizeof(caps) - 1)];
    sname += caps[rand() % (sizeof(caps) - 1)];

    for (int i = 1; i < flength; ++i) 
        fname += low[rand() % (sizeof(low) - 1)];
    for (int i = 1; i < slength; ++i) 
        sname += low[rand() % (sizeof(low) - 1)];

    return fname+" "+sname;
}

double Tester::generateSalary_(){
    double salary = rand() % (MAX_SALARY - MIN_SALARY+1) + MIN_SALARY;
    return salary;
}

unsigned int Tester::generateCustomerData_(vector<string>& names, vector<const char*>& names_c, vector<unsigned int>& ids){
    for(int i = 0; i < NUMBER_OBJECTS; ++i){
        string name=generateName_();
        
        names.push_back(name);
        
        char * cstr = new char [name.length()+1];
        std::strcpy (cstr, name.c_str());
        names_c.push_back(cstr); 

        unsigned int id = rand() % MAX_ID +1;
        ids.push_back(id);
    }

    return NUMBER_OBJECTS;
}

unsigned int Tester::generateEmployeeData_(vector<string>& names, vector<const char*>& names_c, vector<double>& salaries){
    for(int i = 0; i < NUMBER_OBJECTS; ++i){
        string name=generateName_();

        names.push_back(name);

        char * cstr = new char [name.length()+1];
        std::strcpy (cstr, name.c_str());
        names_c.push_back(cstr); 

        double salary = rand() % (MAX_SALARY - MIN_SALARY+1) + MIN_SALARY;
        salaries.push_back(salary);
    }
    return NUMBER_OBJECTS;
}


void Tester::errorOut_(const string& errMsg, unsigned int errBit) {
        cerr << funcname_ << " " << "(fail";
        if (errBit)
                cerr << errBit;
        cerr << "): " << errMsg << endl;
        error_|=(1<<errBit);
}

void Tester::passOut_(const string& passMsg) {
        if (!error_) {
                cerr << funcname_ << " " << "(pass): " << passMsg << endl;
        }
}
