// Write a recursive function to calculate the factorial of a given number. Ok
// Write a recursive function to calculate the nth Fibonacci number. Ok
// Write a recursive function to find the sum of all elements in an array. Ok
// Write a recursive function to count the number of nodes in a binary tree. Ok
// Write a recursive function to reverse a linked list. Ok
// Write a recursive function to check if a string is a palindrome. Ok
// Write a recursive function to find the greatest common divisor (GCD) of two numbers.
// Write a recursive function to find the power of a number.
// Write a recursive function to merge two sorted arrays into a single sorted array.

function factorial(n) {
  if (n === 0) return 1;

  return n * factorial(n - 1);
}

function fib(n) {
  if (n === 0) return 0;

  if (n === 1) return 1;

  return fib(n - 1) + fib(n - 2);
}

function sum(arr, n) {
  if (n <= 0) return 0;

  return arr[n - 1] + sum(arr, n - 1);
}

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.length = 0;
    this.head = null;
  }

  add(data) {
    const node = new Node(data);

    if (!this.head) {
      this.head = node;
      this.length++;
      return;
    }

    let cur = this.head;

    while (cur.next) {
      cur = cur.next;
    }

    this.length++;
    cur.next = node;
  }

  reverse() {
    const r = (q, p) => {
      if (p) {
        r(p, p.next);
        p.next = q;
      } else {
        this.head = q;
      }
    };

    r(null, this.head);
  }

  display() {
    let cur = this.head;

    let list = "";

    while (cur) {
      if (!cur.next) {
        list += cur.data;
      } else {
        list += cur.data + "->";
      }

      cur = cur.next;
    }

    console.log(list);
  }
}

const list = new LinkedList();
list.add(1);
list.add(2);
list.add(3);
list.add(4);
list.add(5);
list.display();
list.reverse();
list.display();


function merge(a1,a2, sizea1, sizea2) {
  let arr3 = []

  if()
}
