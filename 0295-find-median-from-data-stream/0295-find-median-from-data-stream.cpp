class MedianFinder {
public:
    priority_queue<int> lmaxheap;
    priority_queue<int, vector<int>, greater<int>> rminheap;

    MedianFinder() {}

    void addNum(int num) {
        if (lmaxheap.empty()) {
            lmaxheap.push(num);
            return;
        }

        if (num > lmaxheap.top())
            rminheap.push(num);
        else
            lmaxheap.push(num);

        balanceheap();
    }

    void balanceheap() {
        if (rminheap.size() > lmaxheap.size()) {
            lmaxheap.push(rminheap.top());
            rminheap.pop();
        }
        else {
            if (rminheap.size() + 1 < lmaxheap.size()) {
                rminheap.push(lmaxheap.top());
                lmaxheap.pop();
            }
        }
    }

    double findMedian() {
        if (rminheap.size() < lmaxheap.size()) {
            return lmaxheap.top();
        }
        else {
            double ans = lmaxheap.top() + rminheap.top();
            ans /= 2.0;
            return ans;
        }
    }
};