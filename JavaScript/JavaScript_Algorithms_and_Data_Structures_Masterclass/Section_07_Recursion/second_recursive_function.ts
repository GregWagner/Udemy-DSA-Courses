function sumRange(num: number): number {
    // base case
    if (num === 1) return 1;

    // recursive case
    return num + sumRange(num - 1);
}
