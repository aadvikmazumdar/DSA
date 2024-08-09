#include<iostream>
using namespace std;

class BubbleSort{
    private:
        int arr[5] = {32,10,15,12,5};
        
    public:
        void sort(){
            for(int i=0; i<5; i++){
                for(int j=i+1; j<5; j++){
                    if(arr[i] > arr[j]){
                        int x;
                        x = arr[i];
                        arr[i]=arr[j];
                        arr[j]=x;
                    }
                }
            }
        }
        
        void display(){
            for(int i=0; i<5; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    BubbleSort bs;
    cout<<"before sort"<<endl;
    bs.display();
    bs.sort();
    cout<<"after sort"<<endl;
    bs.display();
    return 0;
}



output:
before sort
32 10 15 12 5 
after sort
5 10 12 15 32 