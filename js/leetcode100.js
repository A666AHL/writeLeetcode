// leetcode100.Same Tree
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if(p == null && q == null)
        return true;
    
    if((p == null && q !== null)||(p != null && q == null)||p.val != q.val)
        return false;
   
    if(p && q)
    {
        // 当结点无叶结点时，并且值相等返回 true
        if(p.val == q.val && p.right == null && q.right == null && p.left == null && q.left == null)
            return true;
        var a = isSameTree(p.right, q.right);
        var b = isSameTree(p.left, q.left);
    }
    
    if(a && b)
        return true;
    return false;
};