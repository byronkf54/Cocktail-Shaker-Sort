#include <stdio.h>

// Array to hold all numbers to be sorted
int data[100];


// ALTERNATIVE to sizeof method to find array size
int array_length() {
    int len = 0;
    while (data[len] != '\0') {
        len++;
    }
    return len;
}


// ALTERNATIVE to rand library
// Using the linear congruential generator algorithm
int lcg(int m, int a, int c, int s) {
    int num = (a * s * c) % m;
    if (num < 0) {
        num *= -1;
    }
    return num;
}


// Procedure to swap two elements in the array
void swap_elements(int i, int j) {
    int temp;
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}


// procedure to implement the shaker sort algorithm
void shaker_sort() {
    int size = array_length();
    // loops used to make passes in both directions
    for (int index = 1; index <= size / 2; index++) {
        for (int i = index - 1; i < size - index; i++) {
            if (data[i] > data[i + 1]) {
                swap_elements(i, i + 1);
            }
        }
        for (int i = size - index - 1; i >= index; i--) {
            if (data[i] < data[i - 1]) {
                swap_elements(i, i - 1);
            }
        }
    }
}


// Procedure to add all pseudo random numbers to array
void fill_array() {
    // variables for the LCG algorithm
    int m = 7302012;
    int a = 283;
    int c = 100;
    // All pseudorandom numbers are added here
    data[0] = lcg(m, a, c, 8744003);
    int n = 1;
    while (n < 100) {
        data[n] = lcg(m, a, c, data[n - 1]);
        n++;
    }
}


int main() {
    // Array is filled with 100 random numbers
    fill_array();
    // Sort is started
    shaker_sort();
    // All numbers are printed out in order
    for (int i = 0; i < array_length(); i++)
        printf("%d ", data[i]);
    return 0;
}
