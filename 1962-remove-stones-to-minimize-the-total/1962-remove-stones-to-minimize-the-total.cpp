class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        int sum=accumulate(piles.begin(),piles.end(),0);
        while(k--){
            int temp=pq.top();
            pq.pop();
            sum-=temp/2;
            //temp-=temp-(temp/2);
            pq.push(temp-(temp/2));
            
        }
        return sum;
    }
};