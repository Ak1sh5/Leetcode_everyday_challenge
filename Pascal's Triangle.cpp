

ALGORITHM

/*
Consider These Edge Cases First.
Declare a ans 2-d vector.
let take the edge case for n == 1, than you just push {1} in ans vector.
let take n == 2 you just push again a {1,1} in your answer vector.
now onward n is greater than or equal toh 3 so you need to make the solution using upper rows.
See how we acheive this.
Follow the edges cases in this too,
Now take a variable level and initialise it with 2 as you have done for two levels.
Itearate a fow loop from 1 as 2 rows are already formed, and iterate till n-1 as we need n-1 rows ( array index start from 0).
now declare a vector and iterated another for loop from 0 to less than equal to level.
now we need to take care of edge cases because when we are at the starting and last index.
we have to keep the same element as it in previous row.
we will acces those element from our ans vector, i.e ans[i][0] this will be the first element of our new row.
and, ans[i][level - 1] this will be the last element or our new row.
And, the reaminng elements are the sum of previouse row prior 2 element, which we will calculate from, ans[i][j-1] + ans[i]][j];
At the end return ans vector.
image
*/

//CODE
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        int n =  numRows;
        
        vector<vector<int>> ans;
        if( n == 1)
        {
			// edge case just push {1} to ans vec tor
            ans.push_back({1});
        }
        if(n == 2)
        {
			// edge case just push {1}  and {1,1}  ans vec tor
            ans.push_back({1});
            ans.push_back({1,1});
        }
        
        if(n >=3)
        {
			// repeat these prior steps
            ans.push_back({1});
            ans.push_back({1,1});
            
			// an variable which will tell us how many element to put on current row
            int level = 2;
            
            for(int i = 1; i<n-1; ++i)
            {
                vector<int> v;
                for(int j = 0; j<= level; ++j)
                {
					// edges case first element of current row has to be first element of prev row.
                    if(j == 0)
                        v.push_back(ans[i][0]);
                    else if(j == level)
                    {
							// edges case last element of current row has to be last element of prev row.
                        v.push_back(ans[i][level-1]);
                    }
                    else
                    {
                        v.push_back(ans[i][j-1] + ans[i][j]);
                    }    
                }
                ++level;
                ans.push_back(v);
            }
        }
        
        return ans;
        
    }
};
//And Same This can be acheived by this too the algorithm is same how we using prior row to create new row.

//So if you gone through above algorithm you will understand how the same is acheived by this piece of code.
//class Solution {
//public:
    vector<vector<int>> ans;
    vector<vector<int>> generate(int numRows) {
        for(int i = 0; i<numRows; ++i)
        {
            vector<int> row(i+1, 1);
            for(int j = 1; j<i; ++j)
                row[j] = ans[i-1][j] + ans[i-1][j-1];
            ans.push_back(row);
        }
        return ans;
    }
    
};
