class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct Point
        {
            int x;
            int y;

            int squaredDistanceToOrigin() const { return x*x + y*y; } 

            bool operator>(const Point& other) const { return squaredDistanceToOrigin() > other.squaredDistanceToOrigin(); }
        };

        priority_queue<Point, vector<Point>, greater<Point>> pq;

        for (auto& p : points)
            pq.push({p[0], p[1]});

        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            auto [x, y] = pq.top(); pq.pop();  // C++17 structured binding
            result.push_back({x, y});
        }

        return result;
        
    }
};
