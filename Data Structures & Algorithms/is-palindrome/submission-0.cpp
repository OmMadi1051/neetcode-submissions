class Solution {
public:
    bool isPalindrome(string s) {
        //the main point is how to ignore non alphanumeric characters//does their exist a prebuilt function ////th
        string clean;
        for(auto i:s){
            if(isalnum(i)){
                if(isdigit(i)){
                    clean+=i;
                    continue;
                }
                
                clean+=tolower(i);
            }
        }
        string rev=clean;
        reverse(rev.begin(),rev.end());
        if(clean==rev){
            return true;
        }
        else{
            return false;
        }
    }
};
