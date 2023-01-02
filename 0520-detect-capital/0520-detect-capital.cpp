class Solution {
public:
    bool detectCapitalUse(string word) {
        if(islower(word[0])){
            for(int i=1;i<word.size();i++)
                if(isupper(word[i])) return false;
            return true;
        }
        else if(isupper(word[0])){
            if(isupper(word[1])){
                for(int i=2;i<word.size();i++)
                    if(islower(word[i])) return false;
                //return true;
            }
            else if(islower(word[1])){
                for(int i=2;i<word.size();i++)
                    if(isupper(word[i])) return false;
            }
        }
        return true;
    }
};