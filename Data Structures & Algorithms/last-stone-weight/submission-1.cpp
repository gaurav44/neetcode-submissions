class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for(const auto& stone : stones) 
        {
            pq.push(stone);
        }

        // cout << "hello\n";

        while(pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            // cout << "x: " << x << "\n"; 

            int y = pq.top();
            pq.pop();
            // cout << "y: " << y << "\n";

            if(x != y) pq.push(x-y);
        }

        return pq.empty() ? 0 : pq.top();        
    }
};
