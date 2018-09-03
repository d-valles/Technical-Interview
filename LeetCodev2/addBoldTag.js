/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/
/**
 * @param {string[]} words
 * @param {string} S
 * @return {string}
 */

function addTag (S, start, end) {
    return S.substring(0, start) + '<b>'  + S.substring(start, end) + '</b>' + S.substring(end)
}

var boldWords = function(words, S) {
    let mask = new Array(S.length);
    let answer = ""
    
    for (let i = 0; i <= S.length; i++) {
        for (let j = i; j <= S.length; j++) {
            let word = S.substring(i, j)
            
            if ( words.includes(word) ) {
                mask.fill(1, i, j)
            }
        }
    }
    
    for (let i = 0; i < S.length; i++) {
        if (mask[i] && (i == 0 || !mask[i-1])) {
            answer += "<b>"
        }
        
        answer += S[i]
        
        if (mask[i] && (i == S.length - 1 || !mask[i+1])) {
            answer += "</b>"
        }
    }
    
    return answer
};