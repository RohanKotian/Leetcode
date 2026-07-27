class MedianFinder {
public:
    MedianFinder() {}
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num) {
        if(minHeap.empty() || minHeap.top() < num){
            minHeap.push(num);
        }
        else maxHeap.push(num);
        if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() > maxHeap.size()) return minHeap.top();
        if(minHeap.size() < maxHeap.size()) return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */