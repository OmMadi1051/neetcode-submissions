class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        int n=nums.size();
        while(i<n){
            if(nums[i]==nums[i-1]){
                return true;
            }
            i++;
        }
        return false;
    }
};