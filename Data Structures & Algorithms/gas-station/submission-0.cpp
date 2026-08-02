class Solution {
private:
    void printVisited(const unordered_set<int>& vis) {
        for(auto const& v: vis) {
            cout << v << "\n";
        }
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        unordered_set<int> visited;

        int curGas = 0;
        int curVis = 0;
        int startIdx = 0;
        while (visited.size() < gas.size()) {
            curGas += gas[curVis];
            if(curGas >= cost[curVis]) {
                curGas -= cost[curVis];
                visited.insert(curVis);
                if(curVis + 1 > gas.size() - 1) curVis = 0;
                else curVis++;
                // printVisited(visited);
            } else {
                curGas = 0;
                if(curVis + 1 > gas.size() - 1) curVis = 0;
                else curVis++;
                startIdx = curVis;
                visited.clear();
                continue;
            }
        }

        return startIdx;
        
    }
};
