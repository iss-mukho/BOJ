// 백준 1000: A+B(브론즈 V), https://www.acmicpc.net/problem/1000
const fs = require('fs');

let input = fs.readFileSync('/dev/stdin').toString().split(' ');
let A = parseInt(input[0]);
let B = parseInt(input[1]);

console.log(A+B);
