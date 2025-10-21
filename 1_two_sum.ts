// Last Submission
// 1ms | Beats 88.10%

function twoSum(nums: number[], target: number): number[] {
  const map: { [key: number]: number } = {}
  map[nums[0]] = 0
  const rest0 = target - nums[0];

  for (let i = 1; i < nums.length; i++) {
    if (nums[i] == rest0) return [0, i]
    map[nums[i]] = i
  }

  for (let j = 1; j < nums.length; j++) {
    const rest = target - nums[j]
    const restIndex = map[rest]
    if (restIndex && restIndex != j) return [j, map[rest]]
  }

  return []
};