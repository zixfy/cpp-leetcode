//设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存
//被填满时，它应该删除最近最少使用的项目。 
//
// 它应该支持以下操作： 获取数据 get 和 写入数据 put 。 
//
// 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。 写入数据 put(key, value)
// - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。 
//
// 示例: 
//
// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回  1
//cache.put(3, 3);    // 该操作会使得密钥 2 作废
//cache.get(2);       // 返回 -1 (未找到)
//cache.put(4, 4);    // 该操作会使得密钥 1 作废
//cache.get(1);       // 返回 -1 (未找到)
//cache.get(3);       // 返回  3
//cache.get(4);       // 返回  4
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 188 👎 0


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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)




