class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        def run_tree(node, res):
            if node is None:
                return False
            res += node.val
            if node.left is None and node.right is None:
                return res == targetSum
            return run_tree(node.left, res) or run_tree(node.right, res)

        return run_tree(root, 0)

            
                    