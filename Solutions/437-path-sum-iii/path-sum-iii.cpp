/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    // private: int total=0;
    // private: int count=0;
    // private:
    // void dfs(TreeNode* root,int k,int sum){
    //     if(root==NULL){
    //         return;
    //     }
    //     sum+=root->val;
    //     if(sum==k){
    //         count++;
    //     }
    //     dfs(root->left,k,sum);
    //     dfs(root->right,k,sum);
    // }
// private:
//     void solve(TreeNode* root, int k,int sum,HashMap<int,int>hm){
//         if(root==NULL){
//             return;
//         }
//         sum+=root->val;
//         if(hm.containskey(sum-k)){
//             total+=hm.get(sum-k);
//         }
//         hm.put(sum,getOrDefault(sum,0)+1);
//         solve(root->left,k,sum,hm);
//         solve(root->right,k,sum,hm);
//         hm.put(sum,hm.get(sum)-1);
//         return;
//     }
public:
    #define ll long long
    map<ll ,int> mp;
    int ans=0;
    void solve(TreeNode* root, int targetSum,ll currSum){
        if(root==NULL) return;
        currSum+=root->val;
        ans+=mp[currSum-targetSum];//it mean between the ongoing process there is a place where targetSum is generated.
        mp[currSum]++;
        solve(root->left , targetSum,currSum);
        solve(root->right , targetSum,currSum);
        mp[currSum]--;
        currSum-=root->val;

    }
    int pathSum(TreeNode* root, int k) {
        // TIME COMPLEXITY ORDER OF (N*2).
        // if(root==NULL){
        //     return 0;
        // }
        // // int count=0;
        // dfs(root,k,0);
        // pathSum(root->left,k);
        // pathSum(root->right,k);
        // return count;
        // TIME COMPLEXITY ORDER OF (N).
        // if(root==NULL){
        //     return 0;
        // }
        // HashMap<int,int>hm=new HashMap<>();
        // hm.put(0,1);
        // solve(root,k,0,hm);
        // return total;
        // ALTERNATIVE SOLUTION.(O(N)) TIME.
         mp[0]++;
        ll currSum=0;
        solve(root,k,currSum);
        return ans;

    }
};