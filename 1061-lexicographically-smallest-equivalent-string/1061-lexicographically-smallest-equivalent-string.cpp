class Solution {
public:
    vector<int> head_char;
        int find(int x){
            if(head_char[x]==-1){
                return x;
            }
            return head_char[x]=find(head_char[x]);
        }
    
    void Union(int x, int y){
        int parentx=find(x);
        int parenty=find(y);
        if(parentx==parenty){
            return;
        }
        head_char[max(parentx,parenty)]=min(parentx,parenty);
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        head_char.resize(26,-1);
        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        for(auto i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a')+'a';
        }
        return baseStr;
    }
};