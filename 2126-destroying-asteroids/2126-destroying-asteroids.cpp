class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long planetmass=mass;
        for(int i = 0; i<asteroids.size();i++){
            if(planetmass < asteroids[i]){
                return false;

            }
            else{
                planetmass+=asteroids[i];
            }            

        }
        return true;

        
    }
};