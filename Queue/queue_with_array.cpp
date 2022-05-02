#include <iostream>
#include <string>

using namespace std;

class queue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
       queue() {
           front = rear = -1;
           for(int i = 0; i < 5; i++) {
               arr[i] = 0; 
           }  
       }

       bool isFull() {
           return (rear == 4) ? true : false;
       }

       bool isEmpty() {
           return (rear == -1 && front == -1) ? true : false;
       }

       void Enqueue(int value) {
            if(isFull()) {
                cout << "Queue Overflow" << endl;
            }
            else 
                arr[++rear] = value;
       }

       int Dequeue() {
           int value;
           if(isEmpty()) {
               cout << "Queue Underflow" << endl;
               return 0;
           }
           else if(front + 1 == rear ) {
               value = arr[front + 1];
               rear = front = -1;
           }
           else
                value = arr[++front];

            return value;            
       }

        int count() {
            return rear - front;
        }
    
        void Display() {
            if(isEmpty()) {
                cout << "There is no value in Queue" << endl;
            }
            else {
                for(int i = front + 1; i <= rear; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
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
