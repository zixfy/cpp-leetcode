// 给定在 xy
// 平面上的一组点，确定由这些点组成的任何矩形的最小面积，其中矩形的边不一定平行于
// x 轴和 y 轴。
//
//  如果没有任何矩形，就返回 0。
//
//
//
//  示例 1：
//
//
//
//  输入：[[1,2],[2,1],[1,0],[0,1]]
// 输出：2.00000
// 解释：最小面积的矩形出现在 [1,2],[2,1],[1,0],[0,1] 处，面积为 2。
//
//  示例 2：
//
//
//
//  输入：[[0,1],[2,1],[1,1],[1,0],[2,0]]
// 输出：1.00000
// 解释：最小面积的矩形出现在 [1,0],[1,1],[2,1],[2,0] 处，面积为 1。
//
//
//  示例 3：
//
//
//
//  输入：[[0,3],[1,2],[3,1],[1,3],[2,1]]
// 输出：0
// 解释：没法从这些点中组成任何矩形。
//
//
//  示例 4：
//
//
//
//  输入：[[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
// 输出：2.00000
// 解释：最小面积的矩形出现在 [2,1],[2,3],[3,3],[3,1] 处，面积为 2。
//
//
//
//
//  提示：
//
//
//  1 <= points.length <= 50
//  0 <= points[i][0] <= 40000
//  0 <= points[i][1] <= 40000
//  所有的点都是不同的。
//  与真实值误差不超过 10^-5 的答案将视为正确结果。
//
//
//  Related Topics 几何 数组 数学 👍 66 👎 0

#include <bits/stdc++.h>

// leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

namespace std {
    namespace {

        template<class T>
        inline void hash_combine(std::size_t &seed, T const &v) {
            seed ^= hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }

// Recursive template code derived from Matthieu M.
        template<class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl {
            static void apply(size_t &seed, Tuple const &tuple) {
                HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
                hash_combine(seed, get<Index>(tuple));
            }
        };

        template<class Tuple>
        struct HashValueImpl<Tuple, 0> {
            static void apply(size_t &seed, Tuple const &tuple) {
                hash_combine(seed, get<0>(tuple));
            }
        };
    } // namespace

    template<typename U, typename V>
    struct hash<std::pair<U, V>> {
        size_t operator()(std::pair<U, V> const &tt) const {
            size_t seed = 0;
            hash_combine(seed, tt.first);
            hash_combine(seed, tt.second);
            return seed;
        }
    };

} // namespace std
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>> &points) {
        using i64 = int64_t;
        double ans = i64(numeric_limits<int>::max()) * 2;
        using xy = pair<int, int>;
        unordered_set<xy> pts;
        for (auto const &p: points)
            pts.emplace(p[0], p[1]);
        auto n = points.size();
        auto dis = [](int x1, int x2, int y1, int y2) {
            return i64(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    if (i != j && i != k && j != k) {
                        if ((points[j][0] - points[i][0]) * (points[k][0] - points[i][0]) !=
                            -(points[k][1] - points[i][1]) * (points[j][1] - points[i][1]))
                            continue;
                        auto area = dis(points[i][0], points[j][0], points[i][1], points[j][1]);
                        auto area2 = dis(points[i][0], points[k][0], points[i][1], points[k][1]);

                        if (pts.count({points[j][0] + points[k][0] - points[i][0],
                                       points[j][1] + points[k][1] - points[i][1]})) {
                            ans = min(ans, sqrt(area) * sqrt(area2));
                        }
                    }

        return ans > numeric_limits<int>::max() ? 0 : ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
