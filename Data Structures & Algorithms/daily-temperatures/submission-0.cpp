class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> stk; //temp, idx

        vector<int> result(temperatures.size(), 0);

        stk.push(std::make_pair(temperatures.at(0), 0));

        int count = 1;

        while(count < temperatures.size())
        {
            while(!stk.empty() &&
                  temperatures.at(count) > stk.top().first)
            {
                result.at(stk.top().second) = count - stk.top().second;
                stk.pop();
            }
            stk.push(std::make_pair(temperatures.at(count), count));
            count++;
        }
        return result;
    }
};
