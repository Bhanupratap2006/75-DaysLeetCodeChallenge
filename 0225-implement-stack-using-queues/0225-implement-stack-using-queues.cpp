class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        if (empty()) {
            q1.push(x);
        }
        else if (q1.empty()) {
            q2.push(x);
        }
        else {
            q1.push(x);
        }
    }

    int pop() {
        if (empty())
            return 0;

        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }

            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }

    int top() {
        if (empty())
            return 0;

        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }

            int ele = q2.front();

            // Last element ko wapas q1 me rakhna hai
            q1.push(ele);
            q2.pop();

            return ele;
        }
        else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            int ele = q1.front();

            // Last element ko wapas q2 me rakhna hai
            q2.push(ele);
            q1.pop();

            return ele;
        }
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};