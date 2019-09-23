/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    //滑动窗口
    let window = [];
    let i = 0,
        res = 0;
    while (i < s.length) {
        if (!window.includes(s.charAt(i))) {
            window.push(s.charAt(i));
            if (window.length > res) {
                res = window.length;
            }
            i++;
        } else {
            window.shift();
        }
    }
    return res;
};

let s = "pwwkwe";
console.log(lengthOfLongestSubstring(s));