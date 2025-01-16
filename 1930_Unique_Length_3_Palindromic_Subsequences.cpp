https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".

Solution -

// class Solution {
// public:
//     void findAllSubseq(string &s ,vector<string>&ans ,int index,vector<string>&result){
//         if(index==s.length()){
//             if(!ans.empty()){
//                 string subseq = "";
//                 for(auto i:ans){
//                     subseq+=i;
//                 }
//                 if(subseq.length()==3){
//                 result.push_back(subseq);
//                 }
//             }
//             return;
//         }
//         ans.push_back(string(1,s[index]));
//         //This is necessary because push_back for a std::string expects a char or a     std::string as its argument.the difference in how you use push_back for strings versus arrays (or vectors) is due to the type of data being handled and the requirements of the push_back method for each container type. When working with strings, you may need to create temporary string objects for single characters, while for vectors, you can directly push elements of the same type.
//         findAllSubseq(s,ans,index+1,result);
//         ans.pop_back();
//         findAllSubseq(s,ans,index+1,result);
//     }
//     int countPalindromicSubsequence(string s) {
//         vector<string>ans;
//         vector<string>result;
//         int count = 0;
//         unordered_set<string> uniquePalindromes; 
//         findAllSubseq(s,ans,0,result);
//         for(auto&subseq : result){
//         string reversedSubseq = subseq;
//         reverse(reversedSubseq.begin(),reversedSubseq.end());
//         if(subseq == reversedSubseq && subseq.length()==3){
//             uniquePalindromes.insert(subseq);
//            // count++;
//             }
//         } 
//         return uniquePalindromes.size();  
//     }
// };

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> start(26,-1),end(26,n);
        for(int i=0;i<n;i++){
            if(start[s[i]-'a']==-1) start[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(start[i]!=-1 && end[i]!=n){
                unordered_set<int> st;
                for(int j=start[i]+1;j<end[i];j++) st.insert(s[j]);
                ans+= st.size();
            }
        }
        return ans;
    }
};
