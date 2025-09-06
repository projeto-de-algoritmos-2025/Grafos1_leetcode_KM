#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        const string target = "123450";

        string start_state = "";
        for (const auto& row : board) {
            for (int tile : row) {
                start_state += to_string(tile);
            }
        }
        
        if (start_state == target) {
            return 0;
        }

        queue<pair<string, int>> q;
       
        unordered_set<string> visited;
        
        q.push({start_state, 0});
        visited.insert(start_state);

        const vector<vector<int>> moves_map = {
            {1, 3},       
            {0, 2, 4},    
            {1, 5},       
            {0, 4},       
            {1, 3, 5},     
            {2, 4}        
        };

        while (!q.empty()) {

            auto [current_state, moves] = q.front();
            q.pop();
            
            size_t zero_pos = current_state.find('0');
            
            for (int next_pos : moves_map[zero_pos]) {
                string new_state = current_state;
                swap(new_state[zero_pos], new_state[next_pos]);
                
                if (new_state == target) {
                    return moves + 1;
                }
                
                if (visited.find(new_state) == visited.end()) {
                    visited.insert(new_state);
                    q.push({new_state, moves + 1});
                }
            }
        }
        
    
        return -1;
    }
};