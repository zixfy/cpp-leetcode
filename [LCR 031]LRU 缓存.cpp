//
// 运用所掌握的数据结构，设计和实现一个 LRU (Least Recently Used，最近最少使用) 缓存机制 。 
// 
//
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// 
//
// 进阶：是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 
// 注意：本题与主站 146 题相同：https://leetcode-cn.com/problems/lru-cache/ 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 102 👎 0


#include <string>
#include <vector>
#include <algorithm>
using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
private:
    std::queue<std::pair<int, int>> _q{};
    std::unordered_map<int, std::pair<int, int>> _dict{};
    int _cap;
    int _epoch{0};
public:
    LRUCache(int capacity) : _cap{capacity} {

    }

    int get(int key) {
        ++_epoch;
        if (_dict.count(key) == 0)
            return -1;
        auto& p = _dict[key];
        p.second = _epoch;
        _q.emplace(key, _epoch);
        return p.first;
    }

    void put(int key, int value) {
        ++_epoch;
        if (_dict.count(key) > 0) {
            auto& p = _dict[key];
            p.second = _epoch;
            p.first = value;
        } else {
            while (_dict.size() >= _cap) {
                auto [old_key, old_epo] = _q.front();
                _q.pop();
                if (_dict.count(old_key) && old_epo == _dict[old_key].second)
                    _dict.erase(old_key);

            }
            _dict.emplace(key, std::pair{value, _epoch});
        }
        _q.emplace(key, _epoch);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)




