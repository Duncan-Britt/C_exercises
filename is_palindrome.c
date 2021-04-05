#include <stdio.h>
#include <stdlib.h>

#define positive(n) (~(n)+1)

int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int n_digits(int n) {
    if (n==0) {
        return 1;
    } else if (n<0) {
        n = positive(n);
    }
    
    int count = 0;
    for(int i=1;(n/i)>0;i*=10) {
        count++;
    }
    return count;
}

int is_palindrome(int n) {
    int size = n_digits(n);
    // printf("n: %d, digits: %d\n", n, size);
    int digits[size];
    int place = size-1;
    int leftover = n;
    int digit;
    for(int i=0;i<size;i++) {
        digit = leftover / ipow(10,place);
        leftover %= ipow(10, place);
        place--;
        digits[i] = digit;
    }
    
    int j = size-1;
    for(int i=0;i<size/2;i++) {
        if (digits[i]!=digits[j])
            return 0;
        j--;
    }
    // for(int j=0;j<size;j++)
        // printf("%d", digits[j]);
    
    return 1;
}

int main() {
    printf("%d", is_palindrome(-109151901));
    return 0;
}
