#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

/* return_type function_name(arg_type_1 arg_1, arg_type_2 arg_2, ...) {
    ...
    ...
    ...
    [if return_type is non void]
        return something of type `return_type`;
}
*/



int max_of_four(int a, int b, int c, int d) {
    // Get the array
    int arr[] = { a, b, c, d};
    // Compute the sizes
    int n = sizeof(arr) / sizeof(arr[0]);
    return *max_element(arr, arr + n);
    
}
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}