//
//  linear.cpp
//  cs 32 hw 3
//
//  Created by Jacqueline Nguyen on 2/10/23.

bool anyTrue(const double a[], int n)
{
    if (n <= 0)
        return false;
    if (somePredicate(a[0]))
        return true;
    return anyTrue(a + 1, n - 1);
}

int countTrue(const double a[], int n)
{
    if(n <= 0)
        return 0;
    int count = 0;
    if(somePredicate(a[0]))
        count++;
    return count + countTrue(a + 1, n - 1);
}

int firstTrue(const double a[], int n)
{
    if (n <= 0)
        return -1;
    int position = 0;
    if (somePredicate(a[0]))
        return position;
    firstTrue(a+1, n-1);
    position++;
    return position;
}

int indexOfMinimum(const double a[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return 0;
    int firstHalf = indexOfMinimum(a, n/2);
    int secondHalf = indexOfMinimum(a + n/2, n - n/2) + n/2;
    if (a[firstHalf] <= a[secondHalf])
        return firstHalf;
    return secondHalf;
}

// If all n1 elements of a1 appear in the n2 element array a2, in
      // the same order (though not necessarily consecutively), then
      // return true; otherwise (i.e., if the array a1 is not a
      // not-necessarily-contiguous subsequence of a2), return false.
      // (Of course, if a1 is empty (i.e., n1 is 0), return true.)
      // For example, if a2 is the 7 element array
      //    10 50 40 20 50 40 30
      // then the function should return true if a1 is
      //    50 20 30
      // or
      //    50 40 40
      // and it should return false if a1 is
      //    50 30 20
      // or
      //    10 20 20

bool isIn(const double a1[], int n1, const double a2[], int n2) {
    if (n1 == 0)
        return true;
    if (n1 < 0 || n2 <= 0)
        return false;
    if (n2 > n1)
        return false;
    if (n2 == 1 && a1[0] == a2[0]){
        return true;
    }
    if(a1[0] == a2[0])
        return isIn(a1 + 1, n1 - 1 , a2 + 1, n2 - 1);
    else
        return isIn(a1 + 1, n1 - 1, a2, n2 - 1);
}
