#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t n_rows = matrix.size();
        size_t n_cols = matrix[0].size();

        auto indices = std::views::iota(size_t{0}, n_rows * n_cols);

        auto it = std::ranges::lower_bound(
            indices,
            target,
            {},
            [&](int i) -> int {
                return matrix[i / n_cols][i % n_cols];
            }
        );

        if (it != indices.end()) {
            size_t idx = *it;

            if(matrix[idx / n_cols][idx % n_cols] == target) return true;
        }

        return false;
    }
};
