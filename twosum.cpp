#include <vector>
#include <unordered_map>
using namespace std;

class twosum {
 // Two-pass Hash Table
 /*   
public:vector<int> twoSum(vector<int>& nums, int target) {
       
       unordered_map<int, int> hashtable;

          for(int i = 0; i  < nums.size(); i++){
           hashtable[nums[i]] = i; // here when nums = [2, 7, 11, 15] it maps 2 to index 0, 7 to index 1 and so on. so the hashmap looks like {2:0, 7:1, 11:2, 15:3}
           }

           for(int j = 0; j < nums.size(); j++){
            int complement = target - nums[j];
            if(hashtable.find(complement) != hashtable.end() && hashtable[complement] != j){
                return {j, hashtable[complement]};
            }
           }
           
          return {};*/

          // One-pass Hash Table
          public:vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hashtable;
            for(int i = 0; i < nums.size(); i++){
                int complement = target - nums[i];
                if(hashtable.find(complement) != hashtable.end()){
                    return {hashtable[complement], i};
                }
                hashtable[nums[i]] = i;
            }
            return {};
       }
};