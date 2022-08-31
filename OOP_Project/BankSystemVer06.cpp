/*
* Bank System Ver 0.5
* 작성자: 윤소영
* 내용: AccountHandler라는 이름의 컨트롤 클래스 정의
*/
#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {A=7, B=4, C=2};
enum {normal=1, highcredit=2};

/*
* Entity Class
*/
class Account
{
    int accountID; // 계좌 식별 번호
    int balance; // 계좌 잔고
    char * ownerName; // 소유주명
public:
    Account(int id, int b, char * name) : accountID(id), balance(b)
    {
        ownerName = new char[strlen(name)+1];
        strcpy(ownerName, name);
    }
    Account(const Account &ref) : accountID(ref.accountID), balance(ref.balance)
    {
        ownerName = new char[strlen(ref.ownerName)+1];
        strcpy(ownerName, ref.ownerName);
    }
    int GetAccountId() const {return accountID;}
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccountInfo() const;
    ~Account()
    {
        delete ownerName;
    }
};

void Account::Deposit(int money)
{
    balance += money;
    cout<<"입금 완료\n";
}

int Account::Withdraw(int money)
{
    if(balance < money)
    {
        cout<<"잔액 부족\n";
        return 0;
    }
    balance -= money;
    cout<<"출금 완료\n";
    return money;
}

void Account::ShowAccountInfo() const
{
    cout<<"계좌ID: "<<GetAccountId()<<"\n";
    cout<<"이름: "<<ownerName<<"\n";
    cout<<"잔액: "<<balance<<"\n";
}

/*
NormalAccount 보통예금계좌
*/
class NormalAccount : public Account
{
    int interest;
public:
    NormalAccount(int id, int b, char * name, int interest): Account(id, b, name), interest(interest)
    {}
    virtual void Deposit(int money)
    {
        Account::Deposit(money);
        Account::Deposit(money*(interest/100.0));
    }
};

class HighCreditAccount : public NormalAccount
{
    int creditLevel;
public:
    HighCreditAccount(int id, int b, char * name, int interest, int level) : NormalAccount(id, b, name, interest), creditLevel(level)
    {}
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        Account::Deposit(money*(creditLevel/100.0));
    }
};

/*
* Control Class
*/
class AccountHandler
{
    Account * accountList[100];
    int totalAccNum;
public:
    AccountHandler() : totalAccNum(0)
    { }
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrwaMoney(void);
    void ShowAllAccountInfo(void) const;
    ~AccountHandler()
    {
        for(int i = 0; i < totalAccNum; i++)
        {
            delete accountList[i];
        }
    }
};

void AccountHandler::ShowMenu(void) const
{
    cout<<"--------Menu--------\n";
    cout<<"1. 계좌 개설\n";
    cout<<"2. 입금\n";
    cout<<"3. 출금\n";
    cout<<"4. 전체 계좌 정보 출력\n";
    cout<<"5. 종료\n";
}

void AccountHandler::MakeAccount(void)
{
    int type;
    int id;
    char name[NAME_LEN];
    int balance;
    int interest, level;

    cout<<"[계좌개설]\n";
    cout<<"[계좌종류선택]\n1.보통예금계좌 2.신용신뢰계좌\n";
    cout<<"선택: ";
    cin>>type;
    if(type == normal)
    {
        cout<<"[보통예금계좌 개설]\n";
        cout<<"계좌ID: ";
        cin>>id;
        cout<<"이름: ";
        cin>>name;
        cout<<"입금액: ";
        cin>>balance;
        cout<<"이자율: ";
        cin>>interest;
        accountList[totalAccNum++] = new NormalAccount(id, balance, name, interest);
    }else if(type == highcredit)
    {
        cout<<"[신용신뢰계좌 개설]\n";
        cout<<"계좌ID: ";
        cin>>id;
        cout<<"이름: ";
        cin>>name;
        cout<<"입금액: ";
        cin>>balance;
        cout<<"이자율: ";
        cin>>interest;
        cout<<"신용등급(1toA,2toB,3toC): ";
        cin>>level;
        switch (level)
        {
        case 1:
            accountList[totalAccNum++] = new HighCreditAccount(id, balance, name, interest, A);
            break;
        case 2:
            accountList[totalAccNum++] = new HighCreditAccount(id, balance, name, interest, B);
            break;
        case 3:
            accountList[totalAccNum++] = new HighCreditAccount(id, balance, name, interest, C);
            break;
        default:
            cout<<"질못된 레벨 선택입니다.\n";
            break;
        }
    }
}

void AccountHandler::DepositMoney(void)
{
    int id, money;
    cout<<"[입금]\n계좌ID: ";
    cin>>id;
    cout<<"입금액: ";
    cin>>money;
    for(int i = 0; i < totalAccNum; i++)
    {
        if(accountList[i]->GetAccountId() == id)
        {
            accountList[i]->Deposit(money);
            return;
        }
    }
    cout<<"찾을 수 없는 ID입니다.\n";
}

void AccountHandler::WithdrwaMoney(void)
{
    int id, money;
    cout<<"[출금]\n계좌ID: ";
    cin>>id;
    cout<<"출금액: ";
    cin>>money;
    for(int i = 0; i < totalAccNum; i++)
    {
        if(accountList[i]->GetAccountId() == id)
        {
            accountList[i]->Withdraw(money);
            return;
        }
    }
    cout<<"찾을 수 없는 ID입니다.\n";
}

void AccountHandler::ShowAllAccountInfo(void) const
{
    for(int i = 0; i < totalAccNum; i++)
    {
        accountList[i]->ShowAccountInfo();
        cout<<"\n";
    }
}

int main(void)
{
    AccountHandler manager;
    int choice;
    while(true)
    {
        manager.ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        switch (choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrwaMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccountInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Incorrect Choice!\n Please choice 1~5\n";
            break;
        }
    }
    return 0;
}