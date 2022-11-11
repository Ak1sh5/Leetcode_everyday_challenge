//Very easy
//TC:O(n) SC:O(1)
//Input: nums = [1,1,2]
//Output: 2, nums = [1,2,_]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        nums[j++]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])nums[j++]=nums[i];
        }   
    
        return j;
    }
};
