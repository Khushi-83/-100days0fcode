class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
         priority_queue<int, vector<int>, greater<int>> h;

         for(int i=0;i<nums.size();i++){
             h.push(nums[i]);
             if(h.size()>k)h.pop();
         }
         return h.top();
    }
};
