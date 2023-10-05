# [1. Two Sum (Easy)](https://leetcode.com/problems/two-sum)

#### Difficulty: Easy

#### Data: Oct. 5th, 2023


## Solution 1.
```cpp
// time complexity: O(N^2)
// space complexity: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        for(int i=0; i < nums.size(); i++){
            target -= nums[i];
            for(int j=i+1; j < nums.size(); j++){
                if(target-nums[j] == 0){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
            target+=nums[i];
        } 
        return ans;
    }
};
```






