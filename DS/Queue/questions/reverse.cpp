#include <iostream>
using namespace std;
#include<stack>
#include<queue>

void reverseQueue(queue<int> &input) {
	// Write your code here
    stack<int> st;
    
    while(!input.empty()){
        st.push(input.front());
        input.pop();
    }

	while(!st.empty()){
		input.push(st.top());
		st.pop();
	}
    
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}