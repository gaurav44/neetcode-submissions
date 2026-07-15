#include <algorithm>
#include <ranges>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max = std::ranges::max(piles);
        auto banana_eating_rates = std::views::iota(1, max);

        auto it = std::ranges::partition_point(
            banana_eating_rates,
            [&](size_t banana_eating_rate) {
                
                auto transformed = piles | std::views::transform([banana_eating_rate](size_t x) {
                    // std::cout << static_cast<int>(std::ceil((double) x / 4)) << "\n";
                    return static_cast<int>(std::ceil((double) x / banana_eating_rate));
                });

                auto sum = std::accumulate(transformed.begin(),
                                           transformed.end(),
                                           0);

                return sum > h;
            }
        );

        return *it;
        
    }
};
