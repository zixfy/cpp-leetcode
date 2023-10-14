//给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作： 
//
// 
// 选择礼物数量最多的那一堆。 
// 如果不止一堆都符合礼物数量最多，从中选择任一堆即可。 
// 选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。 
// 
//
// 返回在 k 秒后剩下的礼物数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：gifts = [25,64,9,4,100], k = 4
//输出：29
//解释： 
//按下述方式取走礼物：
//- 在第一秒，选中最后一堆，剩下 10 个礼物。
//- 接着第二秒选中第二堆礼物，剩下 8 个礼物。
//- 然后选中第一堆礼物，剩下 5 个礼物。
//- 最后，再次选中最后一堆礼物，剩下 3 个礼物。
//最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
// 
//
// 示例 2： 
//
// 
//输入：gifts = [1,1,1,1], k = 4
//输出：4
//解释：
//在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。 
//也就是说，你无法获取任一堆中的礼物。 
//所以，剩下礼物的总数量是 4 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= gifts.length <= 10³ 
// 1 <= gifts[i] <= 10⁹ 
// 1 <= k <= 10³ 
// 
//
// Related Topics 数组 模拟 堆（优先队列） 👍 16 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
//
// Created by wwww on 2023/10/1.
//

#ifndef CPP_ADVANCED_CONTAINER_TEMPLATE_PRIORITY_QUEUE_HPP
#define CPP_ADVANCED_CONTAINER_TEMPLATE_PRIORITY_QUEUE_HPP

#include <memory>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <optional>

//
// Created by wwww on 2023/10/1.
//

#ifndef CPP_ADVANCED_CONTAINER_TEMPLATE_PRIORITY_QUEUE_HPP
#define CPP_ADVANCED_CONTAINER_TEMPLATE_PRIORITY_QUEUE_HPP

#include <memory>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <optional>

template<typename T, typename Compare = std::less<T>>
class PriorityQueue {
private:
    using uz = std::size_t;
    std::vector<T> _vec;
    Compare _cmp;
public:
    explicit PriorityQueue(Compare cmp = {}) : _vec{}, _cmp{cmp} {}

    template<typename Iterator>
    PriorityQueue(Iterator begin, Iterator end, Compare cmp = {}): _vec(begin, end), _cmp{cmp} {
        _maintain_from_chaos();
    }

    PriorityQueue(std::initializer_list<T> il, Compare cmp = {}) : PriorityQueue(il.begin(), il.end(), cmp) {}

    template<typename Container>
    explicit PriorityQueue(Container container, Compare cmp = {}): PriorityQueue(container.begin(), container.end(), cmp) {}

    PriorityQueue(PriorityQueue const &) = default;

    PriorityQueue(PriorityQueue &&) noexcept = default;

    PriorityQueue &operator=(PriorityQueue const &) = default;

    PriorityQueue &operator=(PriorityQueue &&) noexcept = default;

    inline auto size() { return _vec.size(); }

    inline auto empty() { return _vec.empty(); }

    T const &peek() {
        if (empty())
            throw std::runtime_error("peek on a empty PriorityQueue");
        return _vec.front();
    }

    T const *try_peek() {
        return empty() ? nullptr : _vec.front();
    }

    template<typename ForwardAsT = T>
    void push(ForwardAsT &&value) {
        _vec.push_back(std::forward<ForwardAsT>(value));
        _maintain_up(_vec.size() - 1);
    }

    T pop() {
        std::swap(_vec.front(), _vec.back());
        auto ret = std::move(_vec.back());
        _vec.pop_back();
        _maintain_down(0);
        return ret;
    }

    inline std::optional<T> try_pop() {
        return empty() ? std::optional<T>{} : pop();
    }

private:
    inline auto _father_of(uz x) {
        return (x - 1) >> 1;
    }

    inline auto _left_of(uz x) {
        return (x << 1) | 1;
    }


    void _maintain_up(uz current) {
        while (current != 0) {
            auto father = _father_of(current);
            if (_cmp(_vec[father], _vec[current]))
                std::swap(_vec[father], _vec[current]);
                // if father < current , let current grow
            else break;
            current = father;
        }
    }

    void _maintain_down(uz current) {
        for (auto child = _left_of(current); child < _vec.size(); child = _left_of(current)) {
            // while there is still any children for current node
            if (auto sibling = child + 1; sibling < _vec.size() && _cmp(_vec[child], _vec[sibling]))
                child = sibling;
            // select biggest child

            if (_cmp(_vec[current], _vec[child]))
                std::swap(_vec[current], _vec[child]);
                // if current  < child, let child grow
            else break;

            current = child;

        }
    }


    inline void _maintain_from_chaos() {
        for (auto i = _vec.size() ; i > 0;)
            _maintain_down(--i);
    }
};

#endif //CPP_ADVANCED_CONTAINER_TEMPLATE_PRIORITY_QUEUE_HPP


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        using i64 = long long;
        auto q = PriorityQueue<int>(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i)
        {
            auto g = q.pop();
            auto new_g = int(std::sqrt(g));
            q.push(new_g);
        }
        i64 ans{0};
        while (!q.empty()) {
            ans += q.pop();
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)




