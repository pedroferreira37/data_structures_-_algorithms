const search = (a, s, e, data) => {
  for (let i = s; i <= e; i++) {
    if (a[i] == data) {
      return i;
    }
  }
  return -1;
};

class Tree {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

const createTrees = (i, p, s, e) => {
  let n = 0;

  const create = (i, p, s, e) => {
    if (s > e) return null;

    const node = new Tree(p[n++]);

    if (s === e) {
      return node;
    }

    const m = search(i, s, e, node.data);
    node.left = create(i, p, s, m - 1);
    node.right = create(i, p, m + 1, e);

    return node;
  };

  return create(i, p, s, e);
};

console.log(
  createTrees([7, 6, 9, 3, 4, 5, 8, 2, 1], [4, 7, 9, 6, 3, 2, 5, 8, 1], 0, 8)
);
