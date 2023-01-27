class Solution {
public:
    set<string> st;
    bool isConcat(string words){
        int n=words.size();
        for(int i=0;i<n;i++){
            string prefix=words.substr(0,i);
            string suffix=words.substr(i,n-i);
            if((st.count(prefix)>=1) && ((st.count(suffix)>=1) || isConcat(suffix))){
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        for(string i:words){
            st.insert(i);
        }
        for(string i:words){
            if(isConcat(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};