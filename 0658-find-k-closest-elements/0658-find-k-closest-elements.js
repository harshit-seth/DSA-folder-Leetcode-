var findClosestElements = function(arr, k, x) {
    arr.sort((a, b) => {
        const diffA = Math.abs(a - x);
        const diffB = Math.abs(b - x);
        return diffA === diffB ? a - b : diffA - diffB;
    });
    return arr.slice(0, k).sort((a, b) => a - b);
};