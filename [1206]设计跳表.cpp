//不使用任何库函数，设计一个 跳表 。 
//
// 跳表 是在 O(log(n)) 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思
//想与链表相似。 
//
// 例如，一个跳表包含 [30, 40, 50, 60, 70, 90] ，然后增加 80、45 到跳表中，以下图的方式操作： 
//
// Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons 
//
// 跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是 O(log(
//n))，空间复杂度是 O(n)。 
//
// 了解更多 : https://en.wikipedia.org/wiki/Skip_list 
//
// 在本题中，你的设计应该要包含这些函数： 
//
// 
// bool search(int target) : 返回target是否存在于跳表中。 
// void add(int num): 插入一个元素到跳表。 
// bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num ，删除其中任意一个即可。 
//
// 
//
// 注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。 
//
// 
//
// 示例 1: 
//
// 
//输入
//["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase",
// "search"]
//[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
//输出
//[null, null, null, null, false, null, true, false, true, false]
//
//解释
//Skiplist skiplist = new Skiplist();
//skiplist.add(1);
//skiplist.add(2);
//skiplist.add(3);
//skiplist.search(0);   // 返回 false
//skiplist.add(4);
//skiplist.search(1);   // 返回 true
//skiplist.erase(0);    // 返回 false，0 不在跳表中
//skiplist.erase(1);    // 返回 true
//skiplist.search(1);   // 返回 false，1 已被擦除
// 
//
// 
//
// 提示: 
//
// 
// 0 <= num, target <= 2 * 10⁴ 
// 调用search, add, erase操作次数不大于 5 * 10⁴ 
// 
//
// Related Topics 设计 链表 👍 255 👎 0
#include <vector>
#include <memory>
#include <random>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)


template<typename K, typename V>
class SkipListImpl {
private:
    constexpr inline static uint8_t MAX_LEVEL = 32;
    constexpr inline static int S = 0xFFFF;
    constexpr inline static int PS = S >> 2;
    struct SkipListNode;
    std::unique_ptr<SkipListNode> m_tail, m_head;
    std::size_t m_length{0};
    std::uint8_t m_level{0};
    std::mt19937 m_rng{std::random_device{}()};


public:
    uint8_t random_level() {
        uint8_t lv = 1;
        // MAXL = 32, S = 0xFFFF, PS = S * P, P = 1 / 4
        while ((m_rng() & S) < PS) ++lv;
        return std::min(MAX_LEVEL, lv);
    }

    SkipListImpl() : m_tail{std::make_unique<SkipListNode>(K{}, V{}, 0)},
                     m_head{std::make_unique<SkipListNode>(K{}, V{}, MAX_LEVEL, m_tail.get())} {

    }

    V *find(const K &key) {
        SkipListNode *p = m_head.get();
        for (int i = m_level; i >= 0; --i) {
            while (true) {
                if (auto nxt = p->forward[i]; nxt != m_tail.get() && nxt->key < key)
                    p = nxt;
                else break;
            }
        }
        p = p->forward[0];
        if (p != m_tail.get() && p->key == key) return &(p->value);
        return nullptr;
    }

    template<typename UK = K, typename UV = V>
    void insert(UK &&key, UV &&value) {
        // 用于记录需要修改的节点
        std::vector<SkipListNode *> update(m_level + 1);
        SkipListNode *p = m_head.get();

        for (int i = m_level; i >= 0; --i) {
            while (true) {
                if (auto nxt = p->forward[i]; nxt != m_tail.get() && nxt->key < key)
                    p = nxt;
                else break;
            }
            update[i] = p;
        }
        p = p->forward[0];

        // 若已存在则修改
//        if (p != m_tail.get() && p->key == key) {
//            p->value = std::forward<UV>(value);
//            return;
//        }

        // 获取新节点的最大层数
        auto lv = random_level();
        if (lv > m_level) {
            lv = ++m_level;
            update.emplace_back(m_head.get());
        }

        // 新建节点
        auto new_node = new SkipListNode(std::forward<UK>(key), std::forward<UV>(value), lv);
        // 在第 0~lv 层插入新节点
        for (int i = lv; i >= 0; --i) {
            p = update[i];
            new_node->forward[i] = p->forward[i];
            p->forward[i] = new_node;
        }

        ++m_length;
    }

    template<typename UK = K, typename UV = V>
    bool erase(UK &&key) {
        // 用于记录需要修改的节点
        std::vector<SkipListNode *> update(m_level + 1);
        SkipListNode *p = m_head.get();
        for (int i = m_level; i >= 0; --i) {
            while (true) {
                if (auto nxt = p->forward[i]; nxt != m_tail.get() && nxt->key < key)
                    p = nxt;
                else break;
            }
            update[i] = p;
        }
        p = p->forward[0];

        // 节点不存在
        if (p == m_tail.get() || p->key != key) return false;

        // 从最底层开始删除
        for (int i = 0; i <= m_level; ++i) {
            // 如果这层没有 p 删除就完成了
            if (update[i]->forward[i] != p)
                break;
            // 断开 p 的连接
            update[i]->forward[i] = p->forward[i];
        }

        delete p;

        // 删除节点可能导致最大层数减少
        while (m_level > 0 && m_head->forward[m_level] == m_tail.get()) --m_level;

        // 跳表长度
        --m_length;
        return true;
    }

private:

    struct SkipListNode {
        uint8_t level;
        K key;
        V value;
        std::unique_ptr<SkipListNode *[]> forward;

        SkipListNode() = delete;

        template<typename UK = K, typename UV = V>
        SkipListNode(UK &&k, UV &&v, uint8_t l, SkipListNode *nxt = nullptr) : key{std::forward<UK>(k)},
                                                                               value{std::forward<UV>(v)}, level{l},
                                                                               forward{std::unique_ptr<SkipListNode *[]>(
                                                                                       new SkipListNode *[l + 1])} {
            std::fill(forward.get(), forward.get() + level + 1, nxt);
        }

    };

};


class Skiplist {
private:
    SkipListImpl<int, int> ls;
public:
    Skiplist() : ls{} {}

    bool search(int target) {
        return ls.find(target) != nullptr;
    }

    void add(int num) {
        ls.insert(num, num);
    }

    bool erase(int num) {
        return ls.erase(num);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
//leetcode submit region end(Prohibit modification and deletion)
