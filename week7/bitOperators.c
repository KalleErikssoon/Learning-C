#include <stdint.h>
#include <stdio.h>
void print_bin(uint32_t num);
int main() {

    print_bin(0);
    print_bin(1);
    print_bin(2);
    print_bin(43);
    print_bin(123456789);
    return 0;
}

void print_bin(uint32_t num) {
    for(int i = 31; i >= 0; i--) {
        if((num >> i) & 1) {
        putchar('1');
        } else {
            putchar('0');
        }
        if(i % 8 == 0 && i != 0) {
            putchar('.');
        }
    }
    putchar('\n');
}