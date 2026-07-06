class Solution {
public:
    string reversePrefix(string word, char ch) {
        int k=-1;
        for(int i=0;i<word.size();i++){
            if(word[i] == ch){
                k=i;
                break;
                if(k == -1)
                    return word; 
            }
            
            
        }
        string ans="";
        
        
        for(int i=k; i>=0;i--)
        {
            ans+=word[i];
            
        }
        for(int i=k+1;i<word.size();i++)
        {
            ans +=word[i] ;
        }
        return ans;
    }
};