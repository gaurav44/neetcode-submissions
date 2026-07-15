#include <queue>
#include <vector>
#include <ranges>

class KthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // min-heap

public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (int n : nums)
        {
            minHeap.push(n);
            if(minHeap.size() > k)
            {
                minHeap.pop();
            } 
        }
    }

    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();    // top is always the kth largest
    }
};