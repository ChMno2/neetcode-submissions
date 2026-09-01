class MedianFinder {
    priority_queue<int , vector<int> , less<int>> minHeap;
    priority_queue<int , vector<int> , greater<int>> maxHeap;
public:
    MedianFinder() {}

    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.size()< minHeap.size()){
            return minHeap.top();
        }
        else{
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};