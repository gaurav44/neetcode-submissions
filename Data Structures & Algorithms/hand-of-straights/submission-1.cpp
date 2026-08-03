class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> counts;

        for(const auto h: hand) {
            counts[h]++;
        }

        for(const auto [num, _]: counts) {
            int start = num;

            while(counts[start-1] > 0) start--;

            while(start <= num) {
                while(counts[start] > 0) {
                    for(int i = start; i < start + groupSize; i++) {
                        if(counts[i] == 0) return false;

                        counts[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};
