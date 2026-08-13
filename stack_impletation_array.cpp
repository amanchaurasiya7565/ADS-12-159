#include<iostream>
using namespace std;
class stack{
    public:
        int *arr;
        int size;
        int top;
        stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        void push (int element ){
            if (size-top >1){
                top++;
                arr[top] = element;
            }
            else
                {
                    cout << "Stack is overflow." << endl;
                }
        }
        void pop(){
            if (top>=0){
                top--;
            }
            else{
                cout << "stack is underflow" << endl;
            }
        }
        int peak(){
            if (top>=0){
                return arr[top];
            }
            else {
                cout << "stack is empty " << endl;
                return -1;
            }
        }
        bool isEmpty (){
            if (top==-1){
                return true;
            }
            else{
                return false;
            }
        }
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    while(!st.isEmpty()){
        cout << st.peak() << " ";
        st.pop();
    }
  
    
}