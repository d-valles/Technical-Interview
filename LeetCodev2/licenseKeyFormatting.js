/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormatting = function(S, K) {
  let arr = S.split("-");
  arr = arr.join("");

  let answer = "";
  let cont = 0;

  for (let i = arr.length - 1; i >= 0; i--) {
    answer = arr[i] + answer;
    cont++;

    if (i != 0 && cont == K) {
      cont = 0;
      answer = "-" + answer;
    }
  }

  return answer.toUpperCase();
};
