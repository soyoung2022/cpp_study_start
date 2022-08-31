#include <iostream>
#include <cstring>
using namespace std;

// 추상 클래스
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
    virtual int GetPay() const = 0; // 가상함수 1
    virtual void ShowSalaryInfo() const = 0; // 가상함수 2
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
        cout<<"salary: "<<salary<<"\n\n";
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
        for(int i = 0; i < empNum; i++)
        {
            emplList[i]->ShowSalaryInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int sum = 0; 
        for(int i = 0; i < empNum; i++)
        {
            sum += emplList[i]->GetPay();
        }
        cout<<"salary num: "<<sum<<"\n";
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

namespace RISK_LEVEL
{ enum{RISK_A=30, RISK_B=20, RISK_C=10}; }

class ForeignSalesWorker : public SalesWorker
{
    const int riskRatio;
public:
    ForeignSalesWorker(char* name, int money, double ratio, int risk) : SalesWorker(name, money, ratio), riskRatio(risk)
    {}
    int GetPay() const
    {
        return SalesWorker::GetPay() + SalesWorker::GetPay() * riskRatio / 100;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<SalesWorker::GetPay()<<"\n";
        cout<<"risk pay: "<<GetPay()-SalesWorker::GetPay()<<"\n";
        cout<<"sum: "<<GetPay()<<"\n\n";
    }
};

int main(void)
{
    EmployeeHandler handler;

    ForeignSalesWorker * fseller1 = new ForeignSalesWorker((char*)"Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker * fseller2 = new ForeignSalesWorker((char*)"Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker * fseller3 = new ForeignSalesWorker((char*)"Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();

    return 0;
}