#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    void Init(int price, int num, int money) {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int SaleApples(int money) {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult() const {
        cout<<"남은 사과 : "<<numOfApples<<endl;
        cout<<"판매 수익 : "<<myMoney<<endl<<endl;
    }
};

class FruitBuyer
{
    // class에서 접근제어 레이블 생략 시 private으로!
    int numOfApples;
    int myMoney;
public:
    void Init(int money){
        myMoney = money;
        numOfApples = 0;
    }
    bool BuyApples(FruitSeller &seller, int money){
        if(money < 0){
            cout<<"구매 액수 전달 오류\n";
            return false;
        }
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
        return true;
    }
    void ShowBuyResult() const {
        cout<<"현재 잔액: "<<myMoney<<endl;
        cout<<"사과 개수: "<<numOfApples<<endl;
    }
};

int main(void) {
    FruitSeller seller;
    seller.Init(1000, 20, 0);
    FruitBuyer buyer;
    buyer.Init(5000);
    buyer.BuyApples(seller, 2000);
    cout<<"파일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();
    cout<<endl;
    if(!buyer.BuyApples(seller, -1000)){
        cout<<"위와 같은 이유로 구매가 불가능합니다.\n";
    }
    cout<<endl;
    cout<<"파일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();

    return 0;
}