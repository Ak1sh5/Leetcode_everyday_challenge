/* no.49 medium oct 28 22
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Apporach is to use hashmap and store same frequency elements together then push all of them into ans 
TC:O(nlogn) SC:O(n)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>mp;
        
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};
