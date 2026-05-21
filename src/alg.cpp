// Copyright 2021 NNTU-CS
#include "alg.h"
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int need = value - arr[i];
        for (int j = len - 1; j > i; j--) {
            if (arr[j] < need) break;
            if (arr[j] == need) count++;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                return count + n * (n - 1) / 2;
            }
            int lc = 1, rc = 1;
            while (left + lc <= right && arr[left + lc] == arr[left]) lc++;
            while (right - rc >= left && arr[right - rc] == arr[right]) rc++;
            count += lc * rc;
            left += lc;
            right -= rc;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
