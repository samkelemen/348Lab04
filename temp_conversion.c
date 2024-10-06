#include <stdio.h>

float celsius_to_fahrenheit(float celsius)
{   
    // Return the conversion from celsius to fahrenhiet
    return (9.0 / 5.0) * celsius + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit)
{   
    //Return the conversion from fahrenheit to celsius
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float celsius_to_kelvin(float celsius)
{   
    // Return the conversion from celsius to kelvin
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin)
{
    // Return the conversion from kelvin to celsius
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit)
{
    // Return the conversion from fahrenheit to kelvin
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

float kelvin_to_fahrenheit(float kelvin)
{
    // Return the conversion from kelvin to fahrenheit
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

void categorize_temperature(float celsius)
{
    // If celsius is less than zero
    if (celsius < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a coat.\n");
    }
    // If celsius is between 0 and 10
    else if (celsius < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    // If celsius celsius is between 10 and 25
    else if (celsius < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    }
    // If celsius is between 25 and 35
    else if (celsius < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: You may be warm.\n");
    }
    // If celsius is greater than 35
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    } 
}

int main()
{
    // Instantiate inputted temp, current_scale, and the temperature on the new scale
    float temp;
    int current_scale;
    int new_scale;
    
    // Instantiate variables to hold the conversion, and the input in celsius
    float new_temp;
    float celsius;

    while (1)
    {
        // Ask user for a temperature, and assign it to temp
        printf("Enter the temperature: ");
        scanf("%f", &temp);

        while (1)
        {
            // Ask user for the scale and assign the input to current_scale
            printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &current_scale);

            // If the input is valid, break out of the input loop
            if (current_scale == 1 || current_scale == 2 || current_scale == 3)
                break;
            // Otherwise, print an error, and ask for new input 
            else
                printf("Invalid choice!\n");
        }

        while (1)
        {
            // Ask user for the scale to convert to and assign it to new_scale
            printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &new_scale);

            // If the input is valid, break out of the input loop
            if (current_scale == 1 || current_scale == 2 || current_scale == 3)
                break;
            // Otherwise, print an error, and ask for new input 
            else
                printf("Invalid choice!\n");
        }

        // Convert the temperature to celsius
        switch (current_scale)
        {   
            // If current scale is celsius, assign celsius to inputted temperature
            case 1: celsius = temp;
                    break;
            // If current scale is fahrenheit, convert to celsius then assign 
            case 2: celsius = fahrenheit_to_celsius(temp);
                    break;
            // If the current scale is kelvin, convert to celsius then assign
            case 3: celsius = kelvin_to_celsius(temp);
                    break;
        }

        // Handle temperature below the minimum possible temperature, -273.15 celsius 
        //or above the maximum (the Planck temperature)
        // If temperature is in the acceptable range, break out of the input loop
        if (celsius > -273.15 && celsius < 1.4E32) 
            break;
        // If the temperature is too high, print so, and ask for new input
        else if (celsius > -273.15)
            printf("Invalid input! The temperature is greater than the Planck temperature!");
        // If the temperature is too low, print so, and ask for new input
        else
            printf("Invalid input! Temperature is lower than the theoretical minimum.\n");
    }

     // Create a unique, two digit identifier for each possible conversion
    // First digit is the current scale. Secnond digit is the new scale
    int identifier = current_scale * 10 + new_scale;

    /* If identifier is equal to the case, do appropriate conversion,
     * print the conversion, and convert to celsius to then categorize
     * the temperature based on the ranges in celsius.
     */
    switch(identifier)
    {   
        case 11: {
                new_temp = temp;
                printf("Warning: no conversion is taking place.\n");
                printf("Converted temperature: %f degrees C\n", new_temp);
                break;
        }
        case 12: {
                new_temp = celsius_to_fahrenheit(temp);
                printf("Converted temperature: %f degrees F\n", new_temp);
                break;
        }
        case 13: {
                new_temp = celsius_to_kelvin(temp);
                printf("Converted temperature: %fK\n", new_temp);
                break;
        }
        case 21: {
                new_temp = fahrenheit_to_celsius(temp);
                printf("Converted temperature: %f degrees C\n", new_temp);
                break;
        }
        case 22: {
                new_temp = new_temp = temp;
                printf("Warning: no conversion is taking place.\n");
                printf("Converted temperature: %f degrees F\n", new_temp);
                break;
        }
        case 23: {
                new_temp = fahrenheit_to_kelvin(temp);
                printf("Converted temperature: %fK\n", new_temp);
                break;
        }
        case 31: {
                new_temp = kelvin_to_celsius(temp);
                printf("Converted temperature: %f degrees C\n", new_temp);
                break;
        }
        case 32: {
                new_temp = kelvin_to_fahrenheit(temp);
                printf("Converted temperature: %f degrees F\n", new_temp);
                break;
        }
        case 33: {
                new_temp = temp;
                printf("Warning: no conversion is taking place.\n");
                printf("Converted temperature: %fK\n", new_temp);
                break;
        }
    }
    // Print the appropriate message for the given temperature in celsius
    categorize_temperature(celsius);
}
