class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int i =0;
        int n = tickets.size();
        for(i=0;i<n;i++)
        {
            q.push(i);
            
        }
        int time=0;
        while(tickets[k]!=0){
            tickets[q.front()]--;
            if(tickets[q.front()]){
                q.push(q.front());

            }
            q.pop();
            time++;
        }
        return time;
        
    }
};