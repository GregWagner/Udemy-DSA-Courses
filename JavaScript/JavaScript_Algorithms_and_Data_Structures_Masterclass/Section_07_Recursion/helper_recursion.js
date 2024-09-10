//recursive using a helper function
function collectOddValues_old(arr) {
    var result = [];
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
// pure recursion
function collectOddValues(arr) {
    var result = [];
    // base case
    if (arr.length === 0) {
        return result;
    }
    if (arr[0] % 2 !== 0) {
        result.push(arr[0]);
    }
    // recursive case (keep adding to results)
    result = result.concat(collectOddValues(arr.slice(1)));
    return result;
}
collectOddValues([1, 2, 3, 4, 5]);
