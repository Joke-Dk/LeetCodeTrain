class MinStack {
public:
    vector<int> data;
    vector<int> record;
    void push(int x) {
        data.push_back(x);
        if(record.empty())
        {
            record.push_back(x);
        }
        else
        {
            record.push_back( min(*(record.end()-1), x));
        }
    }

    void pop() {
        data.pop_back();
        record.pop_back();
    }

    int top() {
        return *(data.end()-1);
    }

    int getMin() {
        return *(record.end()-1);
    }
};