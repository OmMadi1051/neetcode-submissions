class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> res;
        vector<int> selected(n,0);
        for(int i=0;i<n;i++){
            if(selected[i]){continue;}
            vector<string>loc_res;
            int strlen=strs[i].size();
            vector<int>alphaCnt(26,0);
            for(int j=0;j<strlen;j++){
                alphaCnt[strs[i][j]-'a']++;
            }
            loc_res.push_back(strs[i]);
            selected[i]=1;
            for(int j=i+1;j<n;j++){
                vector<int> alphaCk(26,0);
                for(auto k:strs[j]){
                    alphaCk[k-'a']++;
                }
                for(int k=0;k<26;k++){
                    if(alphaCnt[k]!=alphaCk[k]){
                        break;
                    }
                    if(k==25){
                        selected[j]=1;
                        loc_res.push_back(strs[j]);
                    }
                }
            }
            res.push_back(loc_res);
        }
        return res;
    }
};
