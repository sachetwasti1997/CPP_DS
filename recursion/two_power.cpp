//
// Created by sachet on 14/8/22.
//

bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  while (n%2 == 0) n /= 2;
  return n == 1;
}

bool isPowerOfTwo2(int n) {
  if (n == 0) return false;
  long x = n;
  return (x & (-x)) == x;
}