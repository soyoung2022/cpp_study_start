#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard
{
    char * name;
    char * company;
    char * phone_number;
    int pos;
public:
    NameCard(char * myname, char * mycompany, char * phonenumber, int position)
    {
        name = new char(strlen(myname)+1);
        strcpy(name, myname);
        company = new char(strlen(mycompany)+1);
        strcpy(company, mycompany);
        phone_number = new char(strlen(phonenumber)+1);
        strcpy(phone_number, phonenumber);
        switch (position)
        {
        case COMP_POS::CLERK:
            pos = COMP_POS::CLERK;
            break;
        case COMP_POS::SENIOR:
            pos = COMP_POS::SENIOR;
            break;
        case COMP_POS::ASSIST:
            pos = COMP_POS::ASSIST;
            break;
        case COMP_POS::MANAGER:
            pos = COMP_POS::MANAGER;
            break;
        default:
            break;
        }
    }
    NameCard(const NameCard &copy):pos(copy.pos)
    {
        name = new char[strlen(copy.name)+1];
        strcpy(name, copy.name);
        company = new char[strlen(copy.company)+1];
        strcpy(company, copy.company);
        phone_number = new char[strlen(copy.phone_number)+1];
        strcpy(phone_number, copy.phone_number);
    }
    void ShowNameCardInfo() 
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<company<<endl;
        cout<<"전화번호: "<<phone_number<<endl;
        cout<<"직급: ";
        switch (pos)
        {
        case COMP_POS::CLERK:
            cout<<"사원\n\n";
            break;
        case COMP_POS::SENIOR:
            cout<<"주임\n\n";
            break;
        case COMP_POS::ASSIST:
            cout<<"대리\n\n";
            break;
        case COMP_POS::MANAGER:
            cout<<"과장\n\n";
            break;
        default:
            break;
        }
    }
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []phone_number;
    }
};

int main(void) {
    NameCard manClerk((char *)"Lee", (char *)"ABCeng", (char *)"010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR((char *)"Hong", (char *)"OrangeEng", (char *)"010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}