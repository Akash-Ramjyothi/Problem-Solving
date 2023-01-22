class Solution {
public:
    
    vector<vector<string>> result;
    
    void dfs(int ind, string s, vector<string> &str){
        if(ind==s.size()){
            result.push_back(str);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(ind,i,s)){
                str.push_back(s.substr(ind,i-ind+1));
                dfs(i+1,s,str);
                str.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string s){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> str;
        dfs(0,s,str);
        return result;
    }
};