#include<string>
using namespace std;

class vehicle{

    private:
    int maxSpeed;

    protected:
    int numTyres;

    public:
    string color;

    vehicle(){
        cout<<"Vehicle's default constructor!"<<endl;
    }

    vehicle(int z){
        cout<<"Vehicle's Parametrized Constructor!"<<endl;
        maxSpeed = z;
    }

    ~vehicle(){
        cout<<"Vehicle's Destructor!"<<endl;
    }

};