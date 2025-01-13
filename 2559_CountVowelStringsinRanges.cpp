https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-01

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

Solution-

class Solution {
public:
    int isVowel(char ch){
        string str = "aeiou";
        return (str.find(ch) != string::npos);
    }   
    vector<int> vowelStrings(vector<string>& A, vector<vector<int>>& Q) {
        int n = A.size();
        vector<int> Pre(n,0);
        for(int i=0;i<n;i++){
            string temp = A[i];
            if(isVowel(temp[0]) && isVowel(temp[temp.size()-1])){
                Pre[i]++;
            }
            // cout << Pre[]
        }
        for(int i=1;i<n;i++){
            Pre[i] += Pre[i-1];
        }
        vector<int> ans;
        for(auto it : Q){
            int l = it[0];
            int r = it[1];
            if(l==0){ 
                ans.push_back(Pre[r]);
            }else{
                ans.push_back(Pre[r] - Pre[l-1]);
            }
        }
        return ans;
    }
};
