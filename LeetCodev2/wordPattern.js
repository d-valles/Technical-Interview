/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function (pattern, str) {
    return areFollowingPatterns(str.split(' '), pattern.split(''))
};

function areFollowingPatterns(strings, patterns) {
    if (strings.length != patterns.length) return false
    return createValidMap(strings, patterns)
}

function createValidMap(words, patterns) {
    const hashMap = new Map()
    const usedPatterns = new Map()

    for (let i = 0; i < words.length; i++) {
        let key = words[i];
        let current = patterns[i];

        if (!hashMap.has(key) && !usedPatterns.has(current)) {
            hashMap.set(key, current)
            usedPatterns.set(current, key)
        }
        else if (usedPatterns.get(current) != key) {
            console.log(`${usedPatterns.get(current)}, ${key}`)
            return false
        }
    }

    return true;
}