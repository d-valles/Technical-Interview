/**
 * @param {string} S
 * @return {string[]}
 */
function isLetter(c) {
  return c.toLowerCase() != c.toUpperCase();
}

var letterCasePermutation = function(S) {    
    let answer = [S.toLowerCase()]
    
    for (let position = 0; position < S.length; position++) {
        let current = S[position]
        
        if (isLetter(current)) {
            let len = answer.length
            for (let i = 0; i < len; i++) {
                let newS = answer[i]
                console.log(newS[position].toUpperCase())
                newS = newS.split('')
                newS[position] = newS[position].toUpperCase()
                newS = newS.join('')
                answer.push(newS)
            }
        }
    }
    
    return answer
};
