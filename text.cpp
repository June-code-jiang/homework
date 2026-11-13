  #include <iostream>
  #include <cstring>
using namespace std;
class Person{
    protected:char name[100];
              int age; 
    public:Person(char *n,int a){
    strcpy(name,n);
    age=a;
    };
    void show(){
        cout<<name<<":"<<age<<"岁";
    }
};
class Student:public Person{
    protected:char sno[100];
              char major[100];
    public:Student(char*n,int a,char*s,char*m):Person(n,a){
        strcpy(sno,s);
        strcpy(major,m);
        }
        void show(){
            Person::show();
            cout<<"学号"<<sno<<"专业"<<major<<endl;
        }
};
class Teacher:public Person{
protected:char course[100];
public:Teacher(char*n,int a,char *m):Person(n,a){
    strcpy(course,m);
    }
    void show(){
        Person::show();
        cout<<"主讲"<<course<<endl;
    }
};
int main(){
    int n;
    cin>>n;
    char type;
while(n--){
    cin>>type;
    char name[100];
    int age;
    switch(type){
        case 'P':{cin>>name>>age;
            Person p(name,age);
            cout<<"[P]";
            p.show();
            cout<<endl;}break;
        case 'S':{
            char b[100];
            char m[100];
            cin>>name>>age>>b>>m;
            Student s(name,age,b,m);
            cout<<"[S]";
            s.show();
            cout<<endl;
        }break;
        case 'T':{
            char c[100];
            cin>>name>>age>>c;
            cout<<"[T]";
            Teacher t(name,age,c);
            t.show();
            cout<<endl;
        }break;
        default:break;
    }
}
return 0;
}