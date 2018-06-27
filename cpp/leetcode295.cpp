class MedianFinder 
{
public:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>>minQ;
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if (maxQ.empty()) maxQ.push(num);
        else if (num > maxQ.top())
        {
            minQ.push(num);
            if (minQ.size() > maxQ.size())
            {
                maxQ.push(minQ.top());
                minQ.pop();
            }
        }
        else
        {
            maxQ.push(num);
            if (maxQ.size() > minQ.size() + 1)
            {
                minQ.push(maxQ.top());
                maxQ.pop();
            }
        }
    }
    
    double findMedian() 
    {
        if (maxQ.size() > minQ.size()) return maxQ.top();
        return (maxQ.top() + minQ.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */