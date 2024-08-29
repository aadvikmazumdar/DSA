# include <iostream>
using namespace std;

class stack{
    public:
    static const int size = 5;
    int arr[size];
    int tip = 0 ; // position where the element will be added
    void push(int value){
        if(tip >= size){ // if tip is equal to size or greater that means stack is full
            cout<<"stack is full"<<endl;
        }
        else{
            arr[tip] = value;
            tip ++; // incremented as the next element will be "stacked" or kept over the last value which
        }
    }
    int pop(){
        if(tip <= 0){ // stack is empty therefore elements in stack cant be deleted
            cout<<"stack is empty"<<endl; 
            return -1;
        }
        else{
            tip --; // we are removing elements from stack and will be required to move an index below to remove the value
            return arr[tip];
        }
    }
    void print(){
        if(tip<=0){
            cout<<"stack is empty"<<endl;
            }
            else{
                cout<<"stack:";
                for(int i=0;i<tip;i++){
                    cout<<arr[i]<<"  ";
                    }
                    cout<<endl;
                    }
    }
};


int main(){
    stack s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    cout<<"popped: "<<s.pop()<<endl;
    s.print();
    cout<<"popped: "<<s.pop()<<endl;
    s.print();
    cout<<"popped: "<<s.pop()<<endl;
    s.print();
    cout<<"popped: "<<s.pop()<<endl;
    s.print();
    cout<<"popped: "<<s.pop()<<endl;
    s.print();
    cout<<"popped: "<<s.pop()<<endl;
    s.print();
    return 0;
}