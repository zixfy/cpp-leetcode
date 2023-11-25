  // 给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n
  // 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩
  // 阵需要遵循以下规则：
  //
  //
  //  树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
  //  矩阵的列数 n 应该等于 2ʰᵉⁱᵍʰᵗ⁺¹ - 1 。
  //  根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
  //  对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在
  //  res[r+1][c-2ʰᵉⁱᵍʰᵗ⁻ʳ⁻¹] ，右子节点放置在
  // res[r+1][c+2ʰᵉⁱᵍʰᵗ⁻ʳ⁻¹] 。
  //  继续这一过程，直到树中的所有节点都妥善放置。
  //  任意空单元格都应该包含空字符串 "" 。
  //
  //
  //  返回构造得到的矩阵 res 。
  //
  //
  //
  //
  //
  //  示例 1：
  //
  //
  // 输入：root = [1,2]
  // 输出：
  //[["","1",""],
  //  ["2","",""]]
  //
  //
  //  示例 2：
  //
  //
  // 输入：root = [1,2,3,null,4]
  // 输出：
  //[["","","","1","","",""],
  //  ["","2","","","","3",""],
  //  ["","","4","","","",""]]
  //
  //
  //
  //
  //  提示：
  //
  //
  //  树中节点数在范围 [1, 2¹⁰] 内
  //  -99 <= Node.val <= 99
  //  树的深度在范围 [1, 10] 内
  //
  //
  //  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 214 👎 0

  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
  }

  // leetcode submit region begin(Prohibit modification and deletion)
  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
   *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
   * right(right) {}
   * };
   */
  #include "queue"
  #include "string"
  #include "vector"
  using namespace std;

  class Solution {
  public:
    struct Info {
      TreeNode *node;
      int lp, rp;
    };

    vector<vector<string>> printTree(TreeNode *root) {
      std::queue<TreeNode *> bfs;
      bfs.push(root);
      int total_height = 0;
      while (not bfs.empty()) {
        auto qsz = bfs.size();
        for (int i = 0; i < qsz; ++i) {
          auto cur = bfs.front();
          bfs.pop();
          if (cur->left != nullptr)
            bfs.push(cur->left);
          if (cur->right != nullptr)
            bfs.push(cur->right);
        }
        ++total_height;
      }

      vector ans(total_height, vector<string>((1 << total_height) - 1, ""));
      std::queue<Info> bfs2;
      bfs2.push(Info{root, 0, (1 << total_height) - 1});
      int cur_height = 0;
      while (not bfs2.empty()) {
        auto qsz = bfs2.size();
        for (int i = 0; i < qsz; ++i) {
          auto info = bfs2.front();
          auto cur = info.node;
          auto m = (info.lp + info.rp) / 2;
          ans[cur_height][m] = std::to_string(cur->val);
          if (cur->left != nullptr)
            bfs2.push(Info{cur->left, info.lp, m});
          if (cur->right != nullptr)
            bfs2.push(Info{cur->right, m + 1, info.rp});
          bfs2.pop();
        }
        ++cur_height;
        if (cur_height > 10)
          break;
      }

      return ans;
    }
  };
  // leetcode submit region end(Prohibit modification and deletion)
