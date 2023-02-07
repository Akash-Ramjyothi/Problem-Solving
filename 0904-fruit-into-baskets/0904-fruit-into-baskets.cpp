class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int current_max=0;
        int last_fruit=-1;
        int second_last_fruit=-1;
        int res=0;
        int last_fruit_count=0;
        for(int i=0;i<fruits.size();i++){
            if(fruits[i]==last_fruit || fruits[i]==second_last_fruit){
                current_max++;
            }
            else{
                current_max=last_fruit_count+1;
            }
            
            if(fruits[i]==last_fruit){
                last_fruit_count++;
            }
            else{
                last_fruit_count=1;
            }
            if(fruits[i]!=last_fruit){
                second_last_fruit=last_fruit;
                last_fruit=fruits[i];
            }
            res=max(res,current_max);
        }
        return res;
    }
};