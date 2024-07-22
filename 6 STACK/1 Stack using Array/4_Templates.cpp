#include<iostream>
using namespace std;

template <typename Template_1 , typename Template_2>            // For using templates 
class Pair{
    Template_1 x;
    Template_2 y;

    public :

    void setX(Template_1 x){
        this-> x = x;
    }
    Template_1 getX(){
        return x;
    }

    void setY(Template_2 y){
        this-> y = y;
    }
    Template_2 getY(){
        return y;
    }
};

int main(){

    // Pair<int> p1;
    // p1.setX(10);
    // p1.setY(20);
    // cout<< p1.getX()<<"  "<< p1.getY()<<endl;

    // Pair<double> p2;s
    // p2.setX(100.32);
    // p2.setY(34.66);
    // cout<< p2.getX()<<"  "<< p2.getY()<<endl;

    // Pair<char> p3;


    Pair<int,double> p4;                          // Two dif parameters
    p4.setX(100.55);
    p4.setY(100.55);
    cout<< p4.getX()<<"  "<< p4.getY()<<endl;

    
    Pair<Pair<int,double>,char>  p5;              // Three diff parameters Triplet
    Pair<int,double> p6;
    p6.setX(2303);
    p6.setY(81.2);
    p5.setY('H');

    p5.setX(p6);

    cout<< p5.getX().getX()<<"  "<<p5.getX().getY()<<"  "<<p5.getY()<<endl;

 
    return 0;
}