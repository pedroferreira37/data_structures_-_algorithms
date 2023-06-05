const fms = (A) => {
  const hash = new Array(5).fill(0);

  for (let i = 0; i < A.length; i++) {
    hash[A[i]]++;
  }

  for (let j = 1; j <= hash.length; j++) {
    if (hash[j] === 0) {
      return j;
    }
  }
};

console.log(fms([1, 3, 4]));
