class Solution {
public:
    typedef struct Node{
        int val;
        int cnt;
    }Node;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        unordered_map<int,int> hmap;
        for(int i=0;i<n;i++){
            if(hmap.find(nums[i])!=hmap.end()){
                hmap[nums[i]]++;
            }
            else{
                hmap[nums[i]]=1;
            }
        }
        vector<Node> freqVec;
        for(auto i: hmap){
            Node n;
            n.val=i.first;
            n.cnt=i.second;
            freqVec.push_back(n);
        }
        sort(freqVec.begin(),freqVec.end(),[](Node a,Node b){
            return a.cnt>b.cnt;
        });
        // for(int i=0;i<freqVec.size();i++){
        //     cout<<freqVec[i].val<<"--"<<freqVec[i].cnt<<"\n";
        // }
        for(int i=0;i<k;i++){
            res.push_back(freqVec[i].val);
        }
        return res;
    }
};
