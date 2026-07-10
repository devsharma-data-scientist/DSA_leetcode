class MyQueue {
public:
    vector<int> q;
    int st, end;

    MyQueue() {
        st = 0;
        end = -1;
    }

    void push(int x) {
        q.push_back(x);
        end++;
    }

    int pop() {
        if (empty())
            return -1;

        return q[st++];
    }

    int peek() {
        if (empty())
            return -1;

        return q[st];
    }

    bool empty() {
        return st > end;
    }
};