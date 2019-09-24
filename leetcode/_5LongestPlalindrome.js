/**
 * @param {string} s
 * @return {string}
 */
//动态规划
var longestPalindrome = function (s) {
    const dp = [];
    let maxLen = 1,
        maxI = 0,
        maxJ = 0;
    for (let j = 0; j < s.length; j++) {
        dp[j] = [];
        let i = 0;
        for (i; i <= j; i++) {
            if (i === j) {
                dp[i][j] = true;
                continue;
            }
            if (s[i] === s[j]) {
                if (j - i === 1) {
                    dp[i][j] = true;
                    if (2 > maxLen) {
                        maxI = i;
                        maxJ = j;
                        maxLen = 2;
                    }
                } else {
                    if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (j - i + 1 > maxLen) {
                            maxI = i;
                            maxJ = j;
                            maxLen = j - i + 1;
                        }
                    } else {
                        dp[i][j] = false;
                    }
                }
            } else {
                dp[i][j] = false;
            }
        }
    }
    return s.substring(maxI, maxJ + 1);
};

const s = "dcacd";
console.log(longestPalindrome(s));