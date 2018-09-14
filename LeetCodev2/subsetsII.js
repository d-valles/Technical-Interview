/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
  let sets = [[]];
  let hashMap = new Set();
  nums.sort();

  for (let i = 0; i < nums.length; i++) {
    let current = nums[i];
    let len = sets.length;

    for (let j = 0; j < len; j++) {
      let currSet = sets[j].slice();
      currSet.push(current);

      if (!hashMap.has(currSet.toString())) {
        sets.push(currSet);
        hashMap.add(currSet.toString());
      }
    }
  }

  return sets;
};
