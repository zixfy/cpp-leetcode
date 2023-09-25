//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
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
// Related Topics 设计 哈希表 链表 双向链表 👍 2866 👎 0


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <memory>

using u64 = std::uint64_t;
using i64 = std::int64_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;

//leetcode submit region begin(Prohibit modification and deletion)
struct Entry {
    int key, value;
    Entry *prev;
    Entry *next;

    Entry* detach() {
        this->prev->next = this->next;
        this->next->prev = this->prev;
        return this;
    }

    void insert_back(Entry* oth) {
        oth->prev = this;
        oth->next = this->next;
        this->next->prev = oth;
        this->next = oth;
    }

    void insert_front(Entry *oth) {
        oth->next = this;
        oth->prev = this->prev;
        this->prev->next = oth;
        this->prev = oth;
    }
};

class LRUCache {
private:
    std::unique_ptr<Entry> _v_head, _v_tail;
    std::unordered_map<int, std::unique_ptr<Entry>> _dict{};
    int _cap;
public:
    LRUCache(int capacity) : _cap{capacity}, _v_head{new Entry{0, 0, nullptr, nullptr}}, _v_tail{new Entry{0, 0,  nullptr,
                                                                                                        nullptr}} {
        _v_head->next = _v_tail.get();
        _v_tail->prev = _v_head.get();
    }

    int get(int key) {
        if (!_dict.count(key))
            return -1;
        auto p = _dict[key]->detach();
        _v_tail->insert_front(p);
        return p->value;
    }

    void put(int key, int value) {
        if (_dict.count(key)) {
            auto p = _dict[key]->detach();
            p->value = value;
            _v_tail->insert_front(p);
            // move to tail
        }
        else {
            while (_dict.size() >= _cap) {
                auto old_p = _v_head->next->detach();
                _dict.erase(old_p->key);
            }

            auto p = new Entry{key, value, _v_tail->prev, _v_tail.get()};
            _v_tail->insert_front(p);
            _dict.emplace(key, p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)




