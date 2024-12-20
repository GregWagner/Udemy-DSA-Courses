/*
 * Rains
 *
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it can trap after raining.
 *
 * Input:
 *    0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1
 *       [  1  ]  [  4        ]  [  1  ]
 * Output:
 *    6

 * 1) Calculate water for every column
 *    Find the highest element to the left
 *    Find the highest element to the right
 *    Find the minimum of these 2 and subtract the height of the current
 *    element
 *
 * 2) Better
 *    Keep an array that shows the highest element from the left:
 *       0 1 1 2 2 2 2 2 2 3 3 3 3
 *    and from the right:
 *       3 3 3 3 3 3 3 3 3 3 2 2 1
 *    for each position find the minimmum of each of the 2 array's above at that
 *    index and subtract the height of the current element.
 *
 * left   0 1 1 2 2 2 2 3 3 3 3 3
 * right  3 3 3 3 3 3 3 3 2 2 2 1
 * min    0 1 1 2 2 2 2 3 2 2 2 1
 * height 0 1 0 2 1 0 1 3 2 1 2 1
 * water  0 0 1 0 1 2 1 0 0 1 0 0 (min - height)
 *        sum = 6
 */
