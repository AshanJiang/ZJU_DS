/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    // 快慢指针
    let p = 0,
        q = 0;
    for (p; p < nums.length; p++) {
        if (nums[p] !== nums[q]) {
            q += 1;
            nums[q] = nums[p];
        }
    }
    return q + 1;
};

let nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];

let res = removeDuplicates(nums);

console.log(res);
console.log(nums);