/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let max = nums[0],
        curMax = nums[0];
    for (let i = 1; i < nums.length; i++) {
        curMax = Math.max(curMax + nums[i], nums[i]);
        max = Math.max(max, curMax);
    }
    return max;
};

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
nums2 = [-5, -3, -1, 1];
console.log(maxSubArray(nums2));