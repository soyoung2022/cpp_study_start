#include <iostream>
#include <cstring>
using namespace std;

class PermanertWorker
{
    char name[100];
    int salary;
public:
    PermanertWorker(char * name, int money) : salary(money) 
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        cout<<"name: "<<name<<"\n";
        cout<<"salary: "<<GetPay()<<"\n\n";
    }
};

class EmployeeHandler
{
    PermanertWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(PermanertWorker* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSalaryInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for(int i = 0; i < empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout<<"salary sum: "<<sum<<"\n";
    }
    ~EmployeeHandler()
    {
        for(int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main(void)
{
    EmployeeHandler handler; 

    handler.AddEmployee(new PermanertWorker((char*) "KIM", 1000));
    handler.AddEmployee(new PermanertWorker((char*) "LEE", 1500));
    handler.AddEmployee(new PermanertWorker((char*) "JUN", 2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}