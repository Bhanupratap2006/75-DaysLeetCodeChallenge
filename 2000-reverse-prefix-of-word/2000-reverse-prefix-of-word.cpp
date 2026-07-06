class Solution {
public:
    string reversePrefix(string word, char ch) {
        int k=-1;
        for(int i=0;i<word.size();i++){
            if(word[i] == ch){
                k=i;
                
                if(k == -1)
                    return word; 
                    break;
            }
            
            
        }
        reverse(word.begin(),word.begin()+k+1);

        return word;
    }
};