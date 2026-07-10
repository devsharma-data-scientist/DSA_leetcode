class MyStack {
public:
    vector<int> st;
    int tp;

    MyStack() {
        tp = -1;
    }
    
    void push(int x) {
        if(tp == -1){
            tp = 0;
            st.push_back(x);
            return;
        }
        else{
            st.push_back(x);
            tp++;
            return;
        }
    }
    
    int pop() {
        if(tp == -1) return 0;
        else{
            int el = st[tp];
            tp--;
            st.pop_back();
            return el;
        }
    }
    
    int top() {
        if(tp != -1) return st[tp];
        else return 0;
    }
    
    bool empty() {
        if(tp == -1) return true;
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */