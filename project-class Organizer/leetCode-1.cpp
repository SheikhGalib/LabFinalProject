#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int initial = 0;
        int  l = nums.size();
        map <int, int> mp;

        for (int i = 0; i < l; i++)
        {
            mp[nums[i]] = i;
        }
        //sort(mp.begin(), mp.end());  // Map emnei sorted thake

        // for (auto it = mp.begin(); it != mp.end(); ++it) 
        // {
        //     std::cout << it->first << ": " << it->second << std::endl;
        // }

        for (int i = 0; i < l; i++)
        {

                int test = target - nums[i];

                // auto it = lower_bound(mp.begin(), mp.end(), test);
                //auto it = mp.find(test);
                if(mp.count(test) && mp[test] != i)
                {
                    // res.push_back(i);
                    // res.push_back(mp[test]);
                    return {i, mp[test]};
                }

                //break;
            
        }
        return {};

        // return res;
    }
};

int main()
{
    vector <int> v = {3,4,2};
    Solution obj;
    vector <int> result;
    result = obj.twoSum(v, 6);

    for (int i = 0, l = result.size(); i < l; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}