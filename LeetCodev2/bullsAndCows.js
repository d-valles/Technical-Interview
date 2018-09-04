/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
  let hashMap = new Map();
  let bulls = 0;
  let cows = 0;

  for (let i = 0; i < secret.length; i++) {
    let current = secret[i];
    if (current == guess[i]) {
      bulls++;
    } else if (hashMap.has(current)) {
      hashMap.set(current, 1 + hashMap.get(current));
    } else {
      hashMap.set(current, 1);
    }
  }

  console.log(hashMap);

  for (let i = 0; i < guess.length; i++) {
    let current = guess[i];
    if (
      current != secret[i] &&
      hashMap.has(current) &&
      hashMap.get(current) > 0
    ) {
      cows++;
      hashMap.set(current, hashMap.get(current) - 1);
    }
  }

  console.log(hashMap);

  return `${bulls}A${cows}B`;
};
