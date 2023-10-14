//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
// 
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 1986 👎 0
#include "vector"
#include "algorithm"

using namespace std;

#include "random"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class LinkedList {
    ListNode *_tail, *_head;
    int _size;

    struct Iter {
        ListNode *cur;

        ListNode *operator*() {
            return cur;
        }

        bool operator!=(const Iter &oth) {
            return oth.cur != cur;
        }

        Iter &operator++() {
            cur = cur->next;
            return *this;
        }
    };

public:
    LinkedList(ListNode *node) : _tail{node}, _head{node} {
        for (_size = 0; _tail != nullptr; _tail = _tail->next)
            ++_size;
    }

    LinkedList() : LinkedList(nullptr) {}

    inline auto size() { return _size; }


    auto at(int i) {
        auto p = _head;
        for (int j = 0; j < i; ++j)
            p = p->next;
        return p->val;
    }

    auto append(ListNode *node) {
        if (_tail == nullptr)
            _head = _tail = node;
        else {
            _tail->next = node;
            _tail = _tail->next;
        };
        ++_size;
    }

    Iter begin() { return Iter{_head}; }

    auto concat(LinkedList oth) {
        if (_tail == nullptr)
            *this = oth;
        else if (oth._tail == nullptr) { ; }
        else {
            _tail->next = *oth.begin();
            _tail = oth._tail;
            _size += oth._size;
        }
        if (_tail != nullptr && _tail->next != nullptr)
            _tail->next = nullptr;
        return *this;
    }


    Iter end() { return Iter{_tail ? _tail -> next: nullptr}; }

    void print() {
        for (auto node: *this)
            cout << node->val << " -> ";
        cout << '\n';
    }
};

LinkedList qSort(LinkedList ls) {
    static std::random_device rd{};
    static std::mt19937 rng{rd()};
//    cout << "ls : ";
//    ls.print();
    if (ls.size() < 2)
        return ls;
    // [l, r)

    auto base = ls.at(rng() % ls.size());
//    cout << "base : " << base << endl;
    LinkedList l1{}, l2{};
    for (auto node: ls) {
        if (node->val < base || ((node->val == base) && (l1.size() < l2.size())))
            l1.append(node);
        else l2.append(node);
    }
//    cout << "l1 : ";
//    l1.print();
//    cout << "l2 : ";
//    l2.print();
    l1 = qSort(l1);
    l2 = qSort(l2);
    l1.concat(l2);
    return l1;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return *qSort(LinkedList(head)).begin();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
