// factorial computed interatively
function f(num: number): number {
    let answer = 1;
    for (let i = 1; i <= num; ++i) {
        answer *= i;
    }
    return answer;
}

// factorial computed recursively
function factorial(num: number): number {
    // base case
    if (num === 1) return 1;

    // recursive case
    return num * factorial(num - 1);
}

console.log(f(5));
console.log(factorial(5));
