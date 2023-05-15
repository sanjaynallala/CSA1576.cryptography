#include <stdio.h>
#include <math.h>

int main() {
    int num_keys = 1;
for(int i=26;i>= 2;i--)
{
        num_keys *= i;
    }
    double power_of_2 = log2(num_keys);
    printf("The Playfair cipher has approximately 2^%.1f possible keys.\n", power_of_2);
    return 0;
}
