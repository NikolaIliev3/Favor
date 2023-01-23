#include <iostream>
using namespace std;

// Function to compare the magnitude of two numbers
int compareMagnitude(int num1[], int num2[], int len1, int len2) {
    if (len1 > len2) return 1;
    if (len2 > len1) return -1;
    for (int i = 0; i < len1; i++) {
        if (num1[i] > num2[i]) return 1;
        if (num2[i] > num1[i]) return -1;
    }
    return 0;
}

// Function to divide two numbers and find the quotient and remainder
void divide(int num1[], int num2[], int len1, int len2, int quotient[], int &lenq, int remainder[], int &lenr) {
    lenq = lenr = 0;
    int temp[100], len;
    for (int i = 0; i < len1; i++) {
        temp[i] = num1[i];
    }
    len = len1;
    while (compareMagnitude(temp, num2, len, len2) != -1) {
        quotient[lenq++] = 0;
        while (compareMagnitude(temp, num2, len, len2) != -1) {
            for (int i = len - 1; i >= 0; i--) {
                temp[i] -= num2[i];
                if (temp[i] < 0) {
                    temp[i] += 10;
                    temp[i - 1]--;
                }
            }
            while (temp[len - 1] == 0 && len > 1) {
                len--;
            }
            quotient[lenq - 1]++;
        }
        remainder[lenr++] = temp[len - 1];
        if (lenq + lenr < len1) {
            temp[len++] = num1[lenq + lenr];
        }
    }
}

int main() {
    int num1[] = {2, 4, 1, 5, 6};
    int num2[] = {5, 2};
    int len1 = sizeof(num1) / sizeof(num1[0]);
    int len2 = sizeof(num2) / sizeof(num2[0]);
    int quotient[100], lenq, remainder[100], lenr;
    // Compare the magnitude of the two numbers
    int result = compareMagnitude(num1, num2, len1, len2);
    if (result == 1) {
        cout << "First number is greater in magnitude." << endl;
    } else if (result == -1) {
        cout << "Second number is greater in magnitude." << endl;
    } else {
        cout << "Both numbers are equal in magnitude." << endl;
    }
    // Divide the two numbers and find the quotient and remainder
    divide(num1, num2, len1, len2, quotient, lenq, remainder, lenr);
    cout << "Quotient: ";
