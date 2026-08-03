class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        //stack<int>st;
        //using sorting would have required O(nlogn) but we have to solve in O(n)
//        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>>hmap;

        for(int i=0;i<n;i++){
            hmap[nums[i]].push_back(i);
        }
        // vector<int>begPoss(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(hmap.find(nums[i]-1)!=hmap.end()){
                continue;
            }
            st.push(i);
        }
        int max_len=0;
        while(!st.empty()){
            int len=0;
            int indx=st.top();
            st.pop();
            int add=0;
            while(hmap.find(nums[indx]+add)!=hmap.end()){
                add++;
            }
            len=add;
            if(len>max_len){
                max_len=len;
            }
        }
        return max_len;
    }
};
