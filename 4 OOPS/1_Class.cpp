class students {

    public :            // By default Private Access Modif.

    int uid;    
    int age;
    int cgpa;

    private :
    int phoneNum;

    public :
    void display(){
        cout<<"Uid is: "<<uid << ", "<<"Age is: "<< age <<", "<<"CGPA is: " << cgpa <<endl;
    }

    int getPhn(){                   // GET Reads the private value(getters)
        return phoneNum;
    }

    void setPhn(int a){             // SET Change,update the private value(setters)
        if(a<0){
            return;
        }
        phoneNum = a;
    }

    void displayPhn(){
        cout<<"Phone number is : "<<phoneNum<<endl;
    }
};



class phone{
    private:
    int age;

    public:
    int uid,phoneNum;

    void display(){
        cout<<"Phone number is: "<<phoneNum<<", "<<"Age is: "<<age<<", "<<"UID is: "<<uid<<endl;
    }

    phone(){                                 // Default Constructor
        cout<<"1 Constructor called!"<<endl;
    }

    phone(int phoneNum){                           // Parametrized Constructor(contains arg)
        cout<<"2 Constructor called!"<<endl;
        this-> phoneNum=phoneNum;
    }

    phone(int a,int r){
        cout<<"3 Constructor called!"<<endl;
        phoneNum=a;
        age=r;
    }
    
    phone(int a,int b,int c){
        cout<<"4 Constructor called!"<<endl;
        cout<<"This keyword : "<<this <<endl;         // THIS(pointer) keyword holds addr. of current object
        phoneNum=a;
        age=b;
        uid=c;
    }

    ~phone(){                                        // Destructor
        cout<<"Destructor called!"<<endl;
    }
};