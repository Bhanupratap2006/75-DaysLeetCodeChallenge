class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        int n = tickets.size();
        int i =0;
        for(i=0;i<=k;i++){
            time+=min(tickets[i],tickets[k]);
        }
        for(i=k+1;i<n;i++){
            time+=min(tickets[k]-1,tickets[i]);
        }
        return time;
        
    }
};