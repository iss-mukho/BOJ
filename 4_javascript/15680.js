// 백준 15680: 연세대학교(브론즈 V), https://www.acmicpc.net/problem/15680
const fs = require('fs');
const N = fs.readFileSync('/dev/stdin').toString().trim();
console.log((N === '0') ? 'YONSEI' : 'Leading the Way to the Future');
