#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    char name[100];
public:
    Employee(char * name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout<<"name: "<<this->name<<"\n";
    }
};

class PermanentWorker : public Employee
{
    int salary;
public:
    PermanentWorker(char* name, int salary) : Employee(name), salary(salary)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<salary<<"\n";
    }
};

class EmployeeHandler
{
    Employee * emplList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    {}
    void AddEmployee(Employee* emp)
    {
        emplList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        // for(int i = 0; i < empNum; i++)
        // {
            // emplList[i]->ShowSalaryInfo();
        // }
    }
    void ShowTotalSalary() const
    {
        // int sum = 0; 
        // for(int i = 0; i < empNum; i++)
        // {
        //     sum += emplList[i]->GetPay();
        // }
        // cout<<"salary num: "<<sum<<"\n";
    }
    ~EmployeeHandler() 
    {
        for(int i = 0; i < empNum; i++)
        {
            delete emplList[i];
        }
    }
};

int main(void)
{
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker((char*)"KIM", 1000));
    handler.AddEmployee(new PermanentWorker((char*)"LEE", 1500));
    handler.AddEmployee(new PermanentWorker((char*)"JUN", 2000));

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}