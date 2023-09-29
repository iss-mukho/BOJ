const process = (n, grape) => {
  if (n === 1) return grape[0];
  if (n === 2) return grape[0] + grape[1];

  const dp = new Array(n).fill(0);
  dp[1] = grape[0];
  dp[2] = grape[0] + grape[1];

  for (let i = 3; i <= n; ++i)
    dp[i] = Math.max(
      dp[i - 1],
      dp[i - 2] + grape[i - 1],
      dp[i - 3] + grape[i - 2] + grape[i - 1]
    );

  return dp[n];
};

const [n, ...grape] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((num) => Number(num));
console.log(process(n, grape));
