class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num_flips=0;
        int num_ones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                num_ones++;
            }
            else if(s[i]=='0' && num_ones>0){
                num_flips++;
                num_ones--;
            }
        }
        return num_flips;
    }
};