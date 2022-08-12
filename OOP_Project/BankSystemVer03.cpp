/*
* Banking System ver 0.3
* 작성자: 윤소영
* 내용 : Account 클래스에서 복사 생성자 정의하기
*/
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowAllAccount(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
    int accountId;
    char * accountName;
    int balance;
public:
    Account(int id, char * name, int money) : accountId(id), balance(money)
    {
        accountName = new char[strlen(name)+1];
        strcpy(accountName, name);
    }
    Account(const Account &copy) : accountId(copy.accountId), balance(copy.balance)
    {
        accountName = new char[strlen(copy.accountName)+1];
        strcpy(accountName, copy.accountName);
    }
    void Deposit(int money)
    {
        balance+=money;
    }
    bool WithDraw(int money) 
    {
        if(balance < money)
        {
            cout<<"잔액이 부족합니다.\n";
            return false;
        }
        balance -= money;
        return true;
    }
    void ShowAccountInfo()
    {
        cout<<"계좌ID : "<<accountId<<endl;
        cout<<"이 름: : "<<accountName<<endl;
        cout<<"잔 액 : "<<balance<<endl;
    }
    ~Account()
    {
        delete []accountName;
    }
    int GetAccountId() const {
        return accountId;
    }
};

Account * accountList[100]; // 전체 계좌 객체의 주소 저장하는 객체 포인터 배열 
int account_count = 0;

int main(void) {
    int input;
    // 사용자 입력(어떤 일을 할 것인지..)
    while(true) {
        ShowMenu();
        cout<<"선택 : ";
        cin>>input;
        switch (input)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            Deposit();
            break;
        case WITHDRAW:
            Withdraw();
            break;
        case INQUIRE:
            ShowAllAccount();
            break;
        case EXIT:
            for(int i = 0; i < account_count; i++)
            {
                delete accountList[i];
            }
            cout<<"프로그램이 종료되었습니다."<<endl;
            return 0;
        default:
            cout<<"잘못된 번호 선택입니다.. 다시 선택해주세요."<<endl;
            break;
        }
    }
    return 0;
}

void ShowMenu(void) {
    cout<<"------- Menu -------\n1. 계좌개설\n2. 입금\n3. 출금\n4. 계좌정보 전체 출력\n5. 프로그램 종료"<<endl;
}

void MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[계좌개설]\n계좌ID: ";
    cin>>id;
    cout<<"이름: ";
    cin>>name;
    cout<<"입금액: ";
    cin>>balance;
    accountList[account_count++] = new Account(id, name, balance);
}

void Deposit(void) {
    int findId, money;
    cout<<"[임   급]\n계좌 ID : ";
    cin>>findId;
    cout<<"입금액 : "; 
    cin>>money;
    
    for(int i = 0; i < account_count; i++){
        if(findId == accountList[i]->GetAccountId()) {
            accountList[i]->Deposit(money);
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"존재하지 않는 계좌 ID입니다."<<endl<<endl;
}

void Withdraw(void) {
    int findId, money;
    cout<<"[출  금]"<<endl;
    cout<<"계좌ID : ";
    cin>>findId;
    cout<<"출금액 : ";
    cin>>money;
    for(int i = 0; i < account_count; i++){
        if(findId == accountList[i]->GetAccountId()){
            if(accountList[i]->WithDraw(money)){
                cout<<"출금완료"<<endl<<endl;
                return;
            }else{
                cout<<"잔액 부족"<<endl<<endl;
                return;
            }
        }
    }
    cout<<"존재하지 않는 계좌 ID입니다."<<endl<<endl;
}

void ShowAllAccount() {
    for(int i = 0; i < account_count; i++) {
        accountList[i]->ShowAccountInfo();
    }
}