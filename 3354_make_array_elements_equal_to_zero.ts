// Last Submission
// 47ms - Beats 94.12%

function countValidSelections(nums: number[]): number {
  let count = 0;

  const ceros = nums.flatMap((v, i) => v === 0 ? [i] : []);

  ceros.forEach(c => {
    let left_count = 0;
    let right_count = 0;

    nums.forEach((v, i) => {
      i < c ? left_count += v : right_count += v
    });

    if (left_count == right_count) {
      count += 2
    }
    else if (Math.abs(left_count - right_count) == 1) {
      count++
    }
  })

  return count
};
