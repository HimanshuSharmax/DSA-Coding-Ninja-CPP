#include<iostream>
using namespace std;

void RemoveX(char string[]){             // Remove X form string
    if(string[0] == '\0'){
        return;
    }
    if(string[0] != 'x'){
        RemoveX(string + 1);
    }
    else{
        int i=1;
        for( ;string[i] != '\0' ; i++){
            string[i-1] = string[i];
        }
            string[i-1] = string[i];
            RemoveX(string);
    }
}

int length(char string[]){               // Find string length
    if(string[0] == '\0'){               // Base case
        return 0;
    }
    int SmallString = length(string + 1);
    return 1 + SmallString;
}

int main()
{
    char string[100];
    cout<<"Enter the string : ";
    cin>>string;
    
    int output = length(string);
    cout<<"The Length is : "<<output<<endl;


    RemoveX(string);
    cout<<"The Removed X String is : "<<string<<endl;
    output = length(string);
    cout<<"After the Length is : "<<output<<endl;
    return 0;
}       