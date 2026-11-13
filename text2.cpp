#include <iostream>
using namespace std;
class Data{
    int y,m,d;
    public:Data(int year,int month,int day):y(year),m(month),d(day){
                cout<<"Data("<<y<<"-"<<m<<"-"<<d<<")构造"<<endl;
        }
        ~Data(){
            cout<<"Data("<<y<<"-"<<m<<"-"<<d<<")析构"<<endl;
        }
};
class Account{
    protected:int id_;
    double balance_;
        public:
        static int count;
        Account(int id,double balance):id_(id),balance_(balance){
            ++count;
            cout<<"Account("<<id_<<")构造"<<endl;
        }
        ~Account(){
            --count;
            cout<<"Account("<<id_<<")析构"<<endl;
    }
};
int Account::count=0;
class SavingsAccount:public Account{
    Data openData_;
    double rate_;
    public:SavingsAccount(int id,double balance,double rate,int y,int m,int d):
    Account(id,balance),openData_(y,m,d),rate_(rate){
    cout<<"SavingsAccount("<<id_<<")构造,利率"<<rate_<<endl;
    }
    ~SavingsAccount(){
        cout<<"SavingsAccount("<<id_<<")析构"<<endl;
    }
};
int main(){
    cout<<"账户总数:"<<Account::count<<endl;
    cout<<"----进入作用域----"<<endl;
    {SavingsAccount s1(1001,5000,0.03,2026,11,10);
     cout<<"账户总数:"<<Account::count<<endl;  
    SavingsAccount s2(1002,8000,0.025,2026,11,11);
     cout<<"账户总数:"<<Account::count<<endl; 
     cout<<"----离开作用域----"<<endl;
    }
    cout<<"账户总数:"<<Account::count<<endl;
    return 0;
}