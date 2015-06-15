class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = q.size();
        for(int i=0; i<len; ++i)
        {
            int val = q.front();
            q.pop();
            if(i!=len-1)
                q.push(val);
        }
    }

    // Get the top element.
    int top() {
        int len = q.size();
        int val = 0;
        for(int i=0; i<len; ++i)
        {
            val = q.front();
            q.pop();
            q.push(val);
        }
        return val;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};