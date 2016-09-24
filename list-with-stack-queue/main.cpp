#include<iostream>
#include<string>
using namespace std;

struct node{
    char element;
    node* next;
    node(char da, node* next_ = NULL) {
        element = da;
        next = next_;
    }
};

int maxsize = 20;
class queue {
    public:
        queue() {
            head = new node('0', NULL);
            int tempint = maxsize;
            head->next = new node('0', NULL);
            node* temp = head->next;
            tempint--;
            while(tempint--) {
                temp->next = new node('0', NULL);
                temp = temp->next;
            }
            rear = temp;
            rear->next = head->next;
            cursize = 0;
        }
        ~queue() {

        }
        void push(char ele) {
            rear->next->element = ele;
            rear = rear->next;
            cursize++;
        }
        char pop() {
            char output = head->next->element;
            head->next = head->next->next;
            cursize--;
            return output;
        }
        void print() {
            if (cursize == 0) {
                cout << "The queue is empty" << endl;
            } else {
            node* temp = head->next;
            cout << "queue-head ";
            while (temp != rear) {
                cout << temp->element << " ";
                temp = temp->next;
            }
            cout << " "<< rear->element;
            cout << " queue-rear" <<endl;
            }
        }
    private:
        node* head;
        node* rear;
        int cursize; 
};

class stack {
    public:
        stack() {
            head = new node('0', NULL);
            head->next = NULL;
        }
        ~stack() {
            node* cur;
            while(head->next) {
                cur = head->next;
                head->next = cur->next;
                delete cur;
            }
        }
        void push(char ele) {
            node* temp = head->next;
            head->next = new node(ele, temp);
        }
        char pop() {
            node* temp = head->next;
            char output = temp->element;
            head->next = temp->next;
            return output;
        }
        void print() {
            node* temp = head->next;
            cout << "stackTop-";
            while (temp) {
                cout << " " << temp->element << " ";
                temp = temp->next;
            }
            cout << "-stackBottom";
            cout << endl;
        }
    private:
        node* head;
};

int main() {
    string structure;
    cout << "please input the data_structure you want: stack or queue" << endl;
    cin >> structure;
    if (structure== "queue") {
    string operation;
    queue q;
    while(1) {
        cout << "please input your operation: push or pop or quit" << endl;
        cin >> operation;
        if (operation == "push") {
            cout << "please input the element you want to push" << endl;
            char e;
            cin >> e;
            q.push(e);
            q.print();
        } else if (operation == "pop") {
            cout << "pop the quque and the pop element is " << endl;
            cout << q.pop() << endl;
            q.print();
        } else if (operation == "quit"){
            cout << "quit the program" << endl;
            q.print();
            break;
        } else {
            cout << "invalid input" << endl;
            q.print();
        }
    }
    } else if (structure == "stack") {
        string operation;
    stack s;
    while(1) {
        cout << "please input your operation: push or pop or quit" << endl;
        cin >> operation;
        if (operation == "push") {
            cout << "please input the element you want to push" << endl;
            char e;
            cin >> e;
            s.push(e);
            s.print();
        } else if (operation == "pop") {
            cout << "pop the stack and the pop element is " << endl;
            cout << s.pop() << endl;
            s.print();
        } else if (operation == "quit"){
            cout << "quit the program" << endl;
            s.print();
            break;
        } else {
            cout << "invalid input" << endl;
            s.print();
        }
        }
    } else {
        cout << "invalid input" << endl;
    }
    return 0;
}
