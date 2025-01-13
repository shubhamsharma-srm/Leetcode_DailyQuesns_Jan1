https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Solution -

class Solution {
public:
    int findPossibleways(string &s , int index ,int zeroesleft , int onesright){
        int n=s.length();
        if(index == n-1){
            return zeroesleft + onesright;}
        if(s[index]=='0'){
            zeroesleft++;
        }else{
            onesright--;
        }
        int score = 0;
        if (index < s.length() - 1) { // Ensure we don't split at the last character
            score = zeroesleft + onesright; // Calculate score at this split
        }
        return max(score,findPossibleways(s,index+1,zeroesleft,onesright));
    }
    int maxScore(string s) {
        int totalones = 0;
        for(char ch : s){
            if(ch == '1')
                totalones++;
        }
        return findPossibleways(s,0,0,totalones);
    }
};
