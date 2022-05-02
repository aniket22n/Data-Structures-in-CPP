#include <iostream>

using namespace std;

class queue{
    private:
        int front;
        int rear;
        int arr[6]; // We have to leave one cell as blank to identify queue is full / empty.
                    // We can use only 5 cell to store the values.

    public:
       queue() {
           front = rear = 0;
           for(int i = 0; i < 6; i++) {
               arr[i] = 0; 
           }  
       }

       bool isFull() {
           return ((rear + 1) % 6 == front) ? true : false;
       }

       bool isEmpty() {
           return (rear == front) ? true : false;
       }

       void Enqueue(int value) {
            if(isFull()) {
                cout << "Queue Overflow" << endl;
            }
            else {
                    rear = (rear + 1) % 6;
                    arr[rear] = value;
            }
                
       }

       int Dequeue() {
           if(isEmpty()) {
               cout << "Queue Underflow" << endl;
               return 0;
           }
           else {
                front = (front + 1) % 6;
                return arr[front];
           }            
       }

        int count() {
            int c;
            for(int i = front; i != rear; i = (i + 1) % 6)
                c++;
            return c;
        }
    
        void Display() {
            if(isEmpty()) {
                cout << "There is no value in Queue" << endl;
            }
            else {
                for(int i = (front + 1) % 6; i != rear; i = (i + 1) % 6) {
                    cout << arr[i] << " ";
                }
                cout << arr[rear] <<endl;
            }
        }

};


int main() {

    queue q; 
    int option, value;

    do {
        cout << "Select any stack operation ( Enter 0 to exit)" << endl;
        cout <<"1. Enqueue" << endl;
        cout <<"2. Dequeue" << endl;
        cout <<"3. isFull" << endl;
        cout <<"4. isEmpty" << endl;
        cout <<"5. Count" << endl;
        cout <<"6. Display" << endl;
        cout <<"7. Clear Screen" << endl;

        cin >> option;

        switch(option) {

            case 1 : 
                cout << "Enter the value : ";
                cin >> value;
                q.Enqueue(value);
                break;

            case 2 :
                value = q.Dequeue();
                if(value)
                    cout << "Dequeued value " << value << endl;
                break;

            case 3 :
                if(q.isFull())
                    cout << "Yes, Queue is Full" << endl;
                else 
                    cout << "No, Queue is not Full" << endl; 
                break;

            case 4 :
                if(q.isEmpty())
                    cout << "Yes, Queue is Empty" << endl;
                else 
                    cout <<  "No, Queue is not Empty" << endl;
                break;

            case 5 :
                cout << "There are " << q.count() << " values in Queue" << endl;
                break;

            case 6 :
                q.Display();
                break;
            
            case 7 :
                system("cls");
                break;
            
            case 0 :
                cout << "Bye..." << endl;
                break;

        default:
            cout << "Please select valid option" << endl;
    }
    cout << endl;

    }while(option);

    return 0;
}