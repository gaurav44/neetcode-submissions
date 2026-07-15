class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        stack<double> stk;

        vector<double> times(position.size(), 0);

        vector<std::pair<int,int>> combo(position.size());

        for(int i = 0; i < position.size(); i++) 
        {
            combo.at(i) = std::make_pair(position.at(i), speed.at(i));
        }

        std::ranges::sort(combo);

        for(int i = 0; i < position.size(); i++) 
        {
            times.at(i) = (static_cast<double>(target - combo.at(i).first) / combo.at(i).second);
        }

        for(int i = 0; i < position.size(); i++) 
        {
            std::cout << times.at(i) << "\n";
        }

        stk.push(times.at(position.size() - 1));

        for(int i = position.size() - 2; i >=0; i--)
        {
            if(times.at(i) > stk.top()) stk.push(times.at(i));
        }        
        
        return stk.size();
    }
};
