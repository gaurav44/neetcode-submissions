class MedianFinder {
    vector<int> data;
public:
    MedianFinder() {}

    void addNum(int num) {
        data.push_back(num);    
    }
    
    double findMedian() {
        sort(data.begin(), data.end());
        int n = data.size();
        if(n % 2 != 0) return data[n/2];
        else return (data[n/2] + data[n/2 - 1])/2.0;
    }
};
