#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;

        // Step 1: store position and speed
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Step 2: sort by position (descending)
        sort(cars.begin(), cars.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        });

        int fleets = 0;
        double maxTime = 0.0;

        // Step 3: calculate fleets
        for (const auto& car : cars) {
            double time = (double)(target - car.first) / car.second;

            if (time > maxTime) {
                maxTime = time;
                fleets++;
            }
        }

        return fleets;
    }
};