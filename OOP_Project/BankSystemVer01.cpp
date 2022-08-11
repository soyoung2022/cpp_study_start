/*
* Banking System ver 0.1
* 작성자: 윤소영
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
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

typedef struct 
{
    int accountId;
    char accountName[NAME_LEN];
    int balance;
} Account;

Account accountList[100];  // 전체 계좌 저장하는 리스트
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
    cout<<"[계좌개설]\n계좌ID: ";
    cin>>accountList[account_count].accountId;
    cout<<"이름: ";
    cin>>accountList[account_count].accountName;
    cout<<"입금액: ";
    cin>>accountList[account_count].balance;
    account_count++;
}

void Deposit(void) {
    int findId, money;
    cout<<"[임   급]\n계좌 ID : ";
    cin>>findId;
    cout<<"입금액 : "; 
    cin>>money;
    
    for(int i = 0; i < account_count; i++){
        if(findId == accountList[i].accountId) {
            accountList[i].balance += money;
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
        if(findId == accountList[i].accountId){
            if(accountList[i].balance - money >= 0){
                accountList[i].balance -= money;
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
        cout<<"계좌ID : "<<accountList[i].accountId<<endl;
        cout<<"이  름 : "<<accountList[i].accountName<<endl;
        cout<<"잔  액 : "<<accountList[i].balance<<endl<<endl;
    }
}