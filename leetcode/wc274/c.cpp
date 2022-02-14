class Solution {
    #define PLANETS_DESTROYED false
    #define ALL_ASTEROIDS_DESTROYED true
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long cur_mass_of_planets = mass;
        int total_asteroids = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        for(int index = 0; index < total_asteroids; ++index){
            int mass_of_cur_asteroids = asteroids[index];
            if( mass_of_cur_asteroids > cur_mass_of_planets ){
                return PLANETS_DESTROYED;
            }
            cur_mass_of_planets += mass_of_cur_asteroids;
        }
        return ALL_ASTEROIDS_DESTROYED;
        
    }
};
