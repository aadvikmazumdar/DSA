#include<iostream>
using namespace std;

int main(){
    int a=0;
    int b=1;
    int c;
    cout<<"enter fibo series limit: ";
    cin>>c;
    cout<<a<<" "<<b; 
    for(int i=2;i<c;i++){
        int f;
        f=a+b;
        cout<<" "<<f;
        a=b;
        b=f;
    }
    cout<<"f";
    return 0;
}