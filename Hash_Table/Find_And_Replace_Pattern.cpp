/**
 Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example :

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
 * 
 */

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) { 
         
        vector<string> ans; 
        
         
        for(int i =0;i<words.size();i++){     //word list 
             
             map<char ,char>m1; 
             map<char ,char>m2; 
             int flag =1; 
             
             
            for(int j =0;j<words[i].size() ; j++){   //each word 
                 
                auto it = m1.find(pattern[j]); 
                 auto it2 = m2.find(words[i][j]); 
                 
                if(it == m1.end()){ 
                    m1.insert({pattern[j] ,words[i][j]}); 
                } 
                else{ 
                    if(it->second!=words[i][j]){ 
                        flag =0; 
                        break; 
                    } 
                } 
                 
                 
                if(it2 == m2.end()){ 
                    m2.insert({words[i][j] ,pattern[j]} ); 
                } 
                else{ 
                    if(it2->second!=pattern[j]){ 
                        flag =0; 
                        break; 
                    } 
                } 
                 
            } 
            if(flag) 
                ans.push_back(words[i]); 
        } 
       return ans;
        
    }
};


