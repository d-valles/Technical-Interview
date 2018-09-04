/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
  let answer = "";
  let i = 0;
  answer = recursiveHelper(s, i);
  return answer.word;
};

function convertString(s, number) {
  let answer = "";
  for (let i = 0; i < number; i++) {
    answer += s;
  }
  return answer;
}

function findFirst(s, i) {
  for (; i < s.length; i++) {
    if (s[i] == "[") return i;
  }
  return s.length;
}

function recursiveHelper(s, i) {
  let answer = "";

  for (; i < s.length; i++) {
    let current = s[i];

    if ("0123456789".indexOf(current) !== -1) {
      let index = findFirst(s, i);
      let number = Number(s.substring(i, index));

      let reverseWord = recursiveHelper(s, index + 1);
      console.log(number);
      answer += convertString(reverseWord.word, number);
      i = reverseWord.index;
    } else if (current == "]") {
      return { word: answer, index: i };
    } else {
      answer += current;
    }
  }

  return { word: answer, index: i };
}
