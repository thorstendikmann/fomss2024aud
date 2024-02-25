#include <stdio.h>

/**
 * Convert Fahrenheit input value to Celsius value.
 *
 * This will read a float value from the user and calculate the value in degree Celsius 
 * with the following formula:
 * \f$ T_C = (T_F - 32) \cdot \frac{5}{9} \f$
 * 
 * @return 1 in case of errors.
 */
int convertFahrenheitToCelcius(void)
{
	float f;
	float c;

	printf("Enter a value in Fahrenheit: \n");
	// Read value - with error handling
	if (! scanf("%f", &f))
	{
		printf("Error in reading input");
		return 1;
	}
	// Apply formula
	c = ((f-32)*5)/9;

	printf("%f degree Fahrenheit is %f degree Celcius.", f, c);

	return 0;
}

int main(void)
{
	return convertFahrenheitToCelcius();
}
