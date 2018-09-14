/**
 * @param {string} time
 * @return {string}
 */
var nextClosestTime = function(time) {
  let i1 = Number(time[0]);
  let i2 = Number(time[1]);
  let i3 = Number(time[3]);
  let i4 = Number(time[4]);
  return clock(i1, i2, i3, i4);
};

function clock(i1, i2, i3, i4) {
  let hashMap = new Map();
  hashMap.set(i1, true);
  hashMap.set(i2, true);
  hashMap.set(i3, true);
  hashMap.set(i4, true);
  let useAllDigits = true;

  let hours = i1 * 10 + i2;
  let mins = i3 * 10 + i4;

  while (useAllDigits) {
    ++mins;

    if (mins == 60) {
      mins = 0;
      hours++;
      if (hours == 24) {
        hours = 0;
      }
    }

    useAllDigits = !checkMap(hashMap, hours, mins);
  }

  let ii1 = Math.floor(hours / 10);
  let ii2 = Math.floor(hours % 10);
  let ii3 = Math.floor(mins / 10);
  let ii4 = Math.floor(mins % 10);
  return `${ii1}${ii2}:${ii3}${ii4}`;
}

function checkMap(hashMap, hours, mins) {
  let i1 = Math.floor(hours / 10);
  let i2 = Math.floor(hours % 10);
  let i3 = Math.floor(mins / 10);
  let i4 = Math.floor(mins % 10);
  return (
    hashMap.has(i1) && hashMap.has(i2) && hashMap.has(i3) && hashMap.has(i4)
  );
}
