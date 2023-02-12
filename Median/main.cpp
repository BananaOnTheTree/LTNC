#include <iostream>

int find_med(int a, int b, int c, int d, int e) {
  int MED;
  // First 3 comparisions
  if (a > b) {
    if (c > a) {
      MED = a;
    } else {
      MED = (c > b) ? c : b;
    }
  } else {
    if (c > b) {
      MED = b;
    } else {
      MED = (c > a) ? c : a;
    }
  }

  // Last 3 comparisions
  if (d > e) {
    if (d > MED) {
      MED = (MED > e) ? MED : e;
    } else {
      MED = (d > e) ? d : e;
    }
  } else {
    if (e > MED) {
      MED = (MED > d) ? MED : d;
    } else {
      MED = (e > d) ? e : d;
    }
  }
  return MED;
}

int main() {
  int a, b, c, d, e;
  std::cin >> a >> b >> c >> d >> e;
  std::cout << find_med(a, b, c, d, e) << std::endl;
  return 0;
}
