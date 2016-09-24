#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>

using namespace std;


int main(void) {
    string str;
    cin >> str;
    queue<char> q;
    vector<stack<char> > v;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            q.push(str[i]);
            cout << "The 1 get into queue" << endl;
        } else {
            if (v.empty()) {
                stack<char> s;
                s.push(str[i]);
                v.push_back(s);
                cout << "number " << str[i] << " get into stack 1" << endl;
            } else {
                bool flag = false;
                int count = 0;
                for (vector<stack<char> >::iterator iter = v.begin(); iter != v.end(); iter++) {
                    count++;
                    if ((*iter).top() - 1 == str[i]) {
                        (*iter).push(str[i]);
                        cout << "number " << str[i] << " get into stack " << count << endl;
                        flag = true;
                    }
                }
                if (!flag) {
                    stack<char> temp;
                    temp.push(str[i]);
                    v.push_back(temp);
                    cout << "number " << str[i] << " get into stack " << v.size() << endl;
                }
            }
        }
    }
    
    int temp = str.length() - 1;
    while (temp--) {
        int count_ = 0;
        for (vector<stack<char> >::iterator iter = v.begin(); iter != v.end(); iter++) {
        count_++;
        if ((*iter).empty()) {
        } else if ((*iter).top() == q.back()+1) {
            while(!(*iter).empty()) {
                q.push((*iter).top());
                cout << (*iter).top() << " in stack " << count_ << " get into queue" << endl; 
                (*iter).pop();
            }
        }
    }
}
    return 0;
}
