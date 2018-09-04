function reverseParentheses(s) {
  let answer = "";
  let i = 0;
  answer = recursiveHelper(s, i);
  return answer.word;
}

function reverseString(s) {
  return s
    .split("")
    .reverse()
    .join("");
}

function recursiveHelper(s, i) {
  let answer = "";

  for (; i < s.length; i++) {
    let current = s[i];

    if (current === "(") {
      let reverseWord = recursiveHelper(s, i + 1);
      answer += reverseWord.word;
      i = reverseWord.index;
    } else if (current === ")") {
      return { word: reverseString(answer), index: i };
    } else {
      answer += current;
    }
  }

  return { word: answer, index: i };
}
