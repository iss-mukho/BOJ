const fs = require("fs");

const dp: number[] = [...Array(1001)];
const n: number = parseInt(fs.readFileSync("/dev/stdin").toString().trim());

dp[1] = 1;
dp[2] = 3;

for (let i = 3; i <= n; ++i) {
  dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
}

console.log(dp[n]);
