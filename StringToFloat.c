#include <stdio.h>
#include <stdlib.h> // Include the library for atof function
#include <string.h>


float decimal_value(uint8_t nth_decimal_digit, uint8_t val)
{
	uint8_t i;
	uint8_t j;
	float f_ret = 0.0000000;
	float tenth_micro_sec = 0.00000000;

	switch(nth_decimal_digit)
	{
	case 0:
		tenth_micro_sec = 1000000;
		break;
	case 1:
		tenth_micro_sec = 100000;
		break;
	case 2:
		tenth_micro_sec = 10000;
		break;
	case 3:
		tenth_micro_sec = 1000;
		break;
	case 4:
		tenth_micro_sec = 100;
		break;
	case 5:
		tenth_micro_sec = 10;
		break;
	case 6:
		tenth_micro_sec = 1;
		break;
	case 7:
		tenth_micro_sec = 0.1;
		break;
	case 8:
		tenth_micro_sec = 0.01;
		break;
	case 9:
		tenth_micro_sec = 0.001;
		break;
	default:
		break;
	}

	// add up the tenth micro sec regarding the digit in the string after decimal
	for(j=0;j<9;j++)
	{
		if(j==nth_decimal_digit)
		{
			for(i=0;i<val;i++)
			{
				f_ret += tenth_micro_sec;
			}
			break;
		}
		else
		{
			continue;
		}
	}

	return f_ret;
}

void update_f_val(uint8_t val, uint8_t nth_decimal_digit, float *f_val)
{
	uint8_t i;
	for(i=0;i<9;i++)
	{
		if(i==nth_decimal_digit)
		{
			*f_val += decimal_value(nth_decimal_digit, val);
			break;
		}
		else
		{
			continue;
		}
	}
}

float atof_in_tenth_us(char *str)
{
	uint8_t i;
	uint8_t decimal_loc = 0;
	uint8_t str_ptr = 0;
	uint8_t nth_decimal_digit = 0;
	float f_val = 0.00000000;
	char tp_str[50];

	for(i=0;i<50;i++)
	{
		if('.' == str[i] && 0 == decimal_loc)
		{
			// store decimal point location in the received string
			decimal_loc = i;
		}
		if(0x00 == str[i])
		{
			break;
		}
	}

	// move the string point to tenth
	str_ptr = decimal_loc+1;

	// convert the decimal part, 7 decimal places
	for(i=0;i<7;i++)
	{
		switch(str[str_ptr])
		{
		case '0':
			update_f_val(0, nth_decimal_digit, &f_val);
			break;
		case '1':
			update_f_val(1, nth_decimal_digit, &f_val);
			break;
		case '2':
			update_f_val(2, nth_decimal_digit, &f_val);
			break;
		case '3':
			update_f_val(3, nth_decimal_digit, &f_val);
			break;
		case '4':
			update_f_val(4, nth_decimal_digit, &f_val);
			break;
		case '5':
			update_f_val(5, nth_decimal_digit, &f_val);
			break;
		case '6':
			update_f_val(6, nth_decimal_digit, &f_val);
			break;
		case '7':
			update_f_val(7, nth_decimal_digit, &f_val);
			break;
		case '8':
			update_f_val(8, nth_decimal_digit, &f_val);
			break;
		case '9':
			update_f_val(9, nth_decimal_digit, &f_val);
			break;
		default:
			break;
		}

		str_ptr++;
		nth_decimal_digit++;
	}

	// convert the integer part
	strcpy(tp_str, str);
	if((1==decimal_loc&&'0'!=str[decimal_loc-1])||decimal_loc>1)
	{
		// remove the decimal and digit after decimal
		memset(tp_str+decimal_loc, 0x00, sizeof(tp_str));
		// parse the integer
		f_val += (1e7*atof(tp_str));
	}
	// no decimal
	else if(0 == decimal_loc)
	{
		// parse the integer
		f_val += (1e7*atof(tp_str));
	}
	return f_val;
}



int main() {
    // Define an array of 10 strings, each containing 10 characters
    char strings[10][11]; // 10 strings of 10 characters each + '\0' for null-terminator

    // Initialize the array with some sample strings
    strcpy(strings[0], ".000001");  //1us
    strcpy(strings[1], ".00002");  //20us
    strcpy(strings[2], ".00005");  //50us
    strcpy(strings[3], ".00007");  //70us
    strcpy(strings[4], ".0001");   //100us
    strcpy(strings[5], ".0002");   //200us
    strcpy(strings[6], ".0005");   //500us    
    strcpy(strings[7], ".001");    //1ms
    strcpy(strings[8], ".002");    //2ms
    strcpy(strings[9], ".005");    //5ms

    // Convert the strings to floats and print the results
    for (int i = 0; i < 10; i++) 
    {
        printf("%f\n", atof_in_tenth_us(strings[i]));
        float value = atof(strings[i]); // Convert the string to a float
        printf("String %d as Float: %.6f\n", i, value); // Print the result
    }

    return 0; // Return 0 to indicate successful completion
}
