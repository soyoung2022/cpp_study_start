#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    char * title;
    char * isbn;
    int price;
public:
    Book(char * title, char * isbn, int price) : price(price)
    {
        this->title = new char[strlen(title)+1];
        this->isbn = new char[strlen(isbn)+1];
        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }
    void ShowBookInfo()
    {
        cout<<"제목: "<<title<<"\n";
        cout<<"ISBN: "<<isbn<<"\n";
        cout<<"가격: "<<price<<"\n";
    }
    ~Book()
    {
        delete title;
        delete isbn;
    }
};

class EBook : public Book
{
    char * DRMKey;
public:
    EBook(char * title, char * isbn, int price, char * DRMKey) : Book(title, isbn, price)
    {
        this->DRMKey = new char[strlen(DRMKey)+1];
        strcpy(this->DRMKey, DRMKey);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout<<"인증키: "<<DRMKey<<"\n";
    }
    ~EBook()
    {
        delete DRMKey;
    }
};

int main(void)
{
    Book book((char*) "좋은 C++", (char*) "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;

    EBook ebook((char*) "좋은 C++ ebook", (char*) "555-12345-890-1", 10000, (char*) "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}