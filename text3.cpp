#include <iostream>
#include <cstring>
using namespace std;
class Shape{
    protected:char name[100];
    public:
    Shape(char *n){
        strcpy(name,n);
    }
    void show(){
        cout<<name;
    };
};
class Rectangle:public Shape{
    protected:int w_,h_;
    public:
    Rectangle(char *n,int w,int h):Shape(n){
        w_=w;
        h_=h;
    }
    double area()
    {
        return (double)w_*h_;
    }
   double perimeter(){
    return (double)2*(w_+h_);
   }
   void show(){
    cout<<"[R]"<<" ";
    Shape::show();
    cout<<" "<<w_<<"*"<<h_;
    cout<<" "<<"底面积"<<area();
    cout<<" "<<"周长"<<perimeter();
   }
};
class Cuboid:public Rectangle{
double hh_;
public:
Cuboid(char *n,int w,int h,int hh):Rectangle(n,w,h){
    hh_=hh;
}
double area(){
    return (double)2*(Rectangle::area()+w_*hh_+hh_*h_);
}
double volume(){
    return (double)Rectangle::area()*hh_;
}
void show(){
    cout<<"[C]"<<" ";
    Shape::show();
    cout<<" "<<w_<<"*"<<h_<<"*"<<hh_;
    cout<<" "<<"底面积"<<Rectangle::area();
    cout<<" "<<"表面积"<<area();
    cout<<" "<<"体积"<<volume();
}
};
int main(){
    int n;
    cin>>n;
    char type;
    while(n--){
        cin>>type;
        switch(type){
            case'R':{
            char name[100];
            int w,h;
            cin>>name>>h>>w;
            Rectangle r(name,h,w);
            r.show();
            cout<<endl;}break;
            case'C':{
            char name[100];
            int w,h,hh;
            cin>>name>>w>>h>>hh;
            Cuboid c(name,w,h,hh);
            c.show();
            cout<<endl;}break;
        default:break;
        }
    }
    return 0;
}