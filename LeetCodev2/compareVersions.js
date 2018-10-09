/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
  vOne = version1.split(".");
  vTwo = version2.split(".");

  let i = 0;
  let j = 0;
  while (i < vOne.length || j < vTwo.length) {
    let n1 = Number(vOne[i]) || 0;
    let n2 = Number(vTwo[j]) || 0;
    if (n1 < n2) {
      return -1;
    } else if (n1 > n2) {
      return 1;
    }
    i++;
    j++;
  }

  return 0;
};
