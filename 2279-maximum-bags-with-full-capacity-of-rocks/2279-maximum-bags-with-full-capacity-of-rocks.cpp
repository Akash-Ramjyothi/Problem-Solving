class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> availableCapacity(capacity.size());
        
        for(int i=0;i<capacity.size();i++){
            availableCapacity[i]=capacity[i]-rocks[i];
        }
        
        sort(availableCapacity.begin(),availableCapacity.end());
        
        for(int i=0;i<availableCapacity.size();i++){
            
            if(additionalRocks<availableCapacity[i]){
                return i;
            }
            
            if(additionalRocks>=availableCapacity[i]){
                int temp=availableCapacity[i];
                availableCapacity[i]=0;
                additionalRocks=additionalRocks-temp;
            }
        }
        
        int count=0;
        for(int i=0;i<availableCapacity.size();i++){
            if(availableCapacity[i]==0){
                count++;
            }
        }
        return count;
    }
};