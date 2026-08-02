class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //vector<int> res;
        int n=nums.size();
        unordered_map<int,int>hmap;//stores value,index
        for(int i=0;i<n;i++){
            if(hmap.find(nums[i])!=hmap.end()){
                return {hmap[nums[i]],i};
            }
            else{
                hmap[target-nums[i]]=i;
            }
        }
        //return {};
    }
};
