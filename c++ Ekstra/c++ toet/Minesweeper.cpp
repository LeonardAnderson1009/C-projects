#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot = 0;
        for(int nom : nums)
        {
            tot += nom;
        }//I need to start taking c++ courses man

        int leftnoms = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            leftnoms += nums[i];
            if (tot - leftnoms - nums[i] == leftnoms)
            {
                return i;
            }
            
        }
        return -1;
    }
};

int main()
{


    return 0;
}