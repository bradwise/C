#include <stdio.h>
#include <ctype.h>

// From ADC Data sheet, max positive value is 131071 (0x1FFFF)
// 18 bit max value scaled up to 32 bits (left shift 14)
#define MAX_READ        ((int32_t)INT32_MAX & (int32_t)0xFFFFC000)
#define MIN_READ        ((int32_t)INT32_MIN & (int32_t)0xFFFFC000)

int contains_uppercase(const char *str) {
    while (*str) {
        if (isupper(*str)) {
            return 1; // Uppercase character found
        }
        str++;
    }
    return 0; // No uppercase character found
}

int main() {
    char test_string[] = "hello world!";
    
    if (contains_uppercase(test_string)) {
        printf("The string contains uppercase characters.\n");
    } else {
        printf("The string does not contain any uppercase characters.\n");
    }
    
//These are the scale values that the digitizer is using: float32_t scaleValues[] = { 10.44254118, 112.2467794, 420.4783088, 0.0 }
//10V, 100V, 400V, 0V
//10V 8.33762E-05 volts per bit
//100V 0.00089621 volts per bit
//400V 0.003357217 volts per bit
    
//r.scale = scaleValues[range] / (float32_t)MAX_READ;

    return 0;
}



