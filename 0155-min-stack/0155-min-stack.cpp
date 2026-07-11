#include <stack>
#include <set>
using namespace std;

class MinStack {
public:
    stack<int> st;
    multiset<int> ms;

    MinStack() {

    }

    void push(int value) {
        st.push(value);
        ms.insert(value);
    }

    void pop() {
        if(st.empty()) return;

        int x = st.top();
        st.pop();

        ms.erase(ms.find(x));   // sirf ek occurrence delete hoga
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return *ms.begin();     // smallest element
    }
};