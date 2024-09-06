function collectOddValues(arr: number[]) {
    let result: number[] = [];

    function helper(helperInput) {
        // base case
        if (helperInput.length === 0) {
            return;
        }

        if (helperInput[0] % 2 !== 0) {
            result.push(helperInput[0]);
        }

        // recursive case (ignore first element)
        helper(helperInput.slice(1));
    }

    helper(arr);
    return result;
}

collectOddValues([1, 2, 3, 4, 5]);
