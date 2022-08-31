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

class TemporaryWorker : public Employee
{
    int workTime;
    int payPerHour; 
public:
    TemporaryWorker(char* name, int pay) : Employee(name), workTime(0), payPerHour(pay)
    {}
    void AddWorkTime(int time)
    {
        workTime+=time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<"\n\n";
    }
};

class SalesWorker : public PermanentWorker
{
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {}
    void AddSalesResult(int value)
    {
        salesResult+=value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int) (salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<"\n\n";
    }
};

int main(void)
{
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker((char*)"KIM", 1000));
    handler.AddEmployee(new PermanentWorker((char*)"LEE", 1500));

    TemporaryWorker * alba = new TemporaryWorker((char*)"Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker * seller = new SalesWorker((char*) "Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}