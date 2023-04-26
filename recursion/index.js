// Write a recursive function to calculate the factorial of a given number.
// Write a recursive function to calculate the nth Fibonacci number.
// Write a recursive function to find the sum of all elements in an array.
// Write a recursive function to count the number of nodes in a binary tree.
// Write a recursive function to reverse a linked list.
// Write a recursive function to check if a string is a palindrome.
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
  #init;

  constructor(arr) {
    this.head;

    this.#init = () => {
      const head = new Node(arr[0]);

      let cur = head;

      for (let i = 1; i < arr.length; i++) {
        const temp = new Node(arr[i]);

        cur.next = temp;

        cur = cur.next;
      }

      return head;
    };

    this.head = this.#init();
  }
}

const list = new LinkedList([1, 2, 3, 4]);

console.log(list);
