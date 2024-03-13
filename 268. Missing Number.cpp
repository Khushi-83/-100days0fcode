class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();  
    int actualSum = 0;

    int expectedSum= (n*(n+1))/2; //gaussian Sum
    
    for(int num: nums)
        actualSum+=num;

    return expectedSum - actualSum;
    }
};
