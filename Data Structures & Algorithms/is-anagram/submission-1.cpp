class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hmap;
        for(auto i:s){
            if(hmap.find(i)!=hmap.end()){
                hmap[i]++;
            }
            else{
                hmap[i]=1;
            }
        }
        for(auto i:t){
            if(hmap.find(i)==hmap.end()||hmap[i]==0){
                return false;
            }
            else{
                hmap[i]--;
            }
        }
        for(const auto &i:hmap){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
};
