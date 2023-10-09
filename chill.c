/*
 * 
 * Johan Cruz Hernandez
 * September 24, 2023
 * 
 * 
 * Usage: 
 *     - chill [arg1] [arg2]
 *         - [arg1]: optional argument -> represents temperature between -99 and 50 (non-incluseive) degrees Fahrenheit
 *         - [arg2]: optional argument -> represents wind between 0.5 and 231 (inclusive) miles per hour
 *     - case 1: zero arguments passed:
 *         - returns a table of temp, wind velocity, and wind chill for a given set of values
 *     - case 2: one argument (temperature)
 *         - returns a table of wind chill values provided a temperature and a preselected wind velocity values
 *     - case 3: two arguments (temperature and wind)
 *         - returns the wind chill factor given a temperature and wind velocity
 * 
 * 
 * Exit Codes:
 *     - exit(0): successful program
 *     - exit(1): general error -> temperature or wind velocity arguments are out of bounds
 *     - exit(2): usage error (user passed in too many parameters)
 *     - exit(3): format of arguments are not in form of a float
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Function Prototypes
void printHeaderColumns(void);
float calWindChill(int temp, int wind);
bool validArgumentFormat(const char string[]);
float str2float(const char string[]);
bool isTempInRange(const char string[]);
bool isWindInRange(const char string[]);

/*
 * main: returns the wind chill factor given no arguments, 1 argument, 2 arguments, and 3 arguments or more

 * argv[1]: (optional) represents the temperature in degrees Fahrenheit
 * argv[2]: (optional) represents the wind velocity in MPH
*/
int 
main(const int argc, const char* argv[]) {

    // case: no arguments are passed
    if (argc == 1) {
        printHeaderColumns();
        for (float temp = -10; temp <= 40; temp += 10) {
            for (float wind = 5.0; wind <= 15; wind += 5) {
                float windChill = calWindChill(temp, wind);
                printf("%.1f   %.1f    %.1f \n", temp, wind, windChill);
            }
            printf("\n");
        }
    }
    // case 2: one argument (temperature) is passed
    if (argc == 2) {

        // format of first argument is a float
        if (validArgumentFormat(argv[1])) {
            
            // temp argument is in bounds
            if (isTempInRange(argv[1])) {
                printHeaderColumns();
                for (float wind = 5.0; wind <= 15; wind += 5) {
                    float windChill = calWindChill(str2float(argv[1]), wind);
                    printf("%.1f    %.1f    %.1f \n", str2float(argv[1]), wind, windChill);
                }
            }

            // temp argument is not in bounds
            else if (!isTempInRange(argv[1])) {
                printf("Error: Temperature must be greater than -99 degrees Fahrenheit and less then 50 degrees Fahrenheit.\n");
                exit(1);
            }
        }

        // format of first argument is not a float
        else if (!validArgumentFormat(argv[1])) {
            printf("First argument [%s] is not a valid float. \n", argv[1]);
            exit(3);
        }

    }
    // case 3: two arguments (temperature and wind speed)
    if (argc == 3) {

        // argv[1]: refers to temperature argument (Fahrenheit)
        // argv[2]: refers to wind velocity argument (MPH)

        // valid arguments
        if (validArgumentFormat(argv[1]) && validArgumentFormat(argv[2])) {
            // temp and wind velocity are out of bounds
            if (!isTempInRange(argv[1]) && !isWindInRange(argv[2])) {
                printf("Error: Temperature must be greater than -99 degrees Fahrenheit and less then 50 degrees Fahrenheit.\n");
                printf("Error: Wind must be greater than or equal to 0.5 MPH and less than or equal to 231 MPH.\n");
                exit(1);
            }

            // temp is in bounds, wind velocity is not in bounds
            else if(isTempInRange(argv[1]) && !isWindInRange(argv[2])) {
                printf("Error: Wind must be greater than or equal to 0.5 MPH and less than or equal to 231 MPH.\n");
                exit(1);
            }

            // temp is not in bounds, wind velocity is in bounds
            else if(!isTempInRange(argv[1]) && isWindInRange(argv[2])) {
                 printf("Error: Temperature must be greater than -99 degrees Fahrenheit and less then 50 degrees Fahrenheit.\n");
                 exit(1);
            }

            // temp and wind are in bounds
            else if (isTempInRange(argv[1]) && isWindInRange(argv[2])) {
                printHeaderColumns();
                float windChill = calWindChill(str2float(argv[1]), str2float(argv[2]));
                printf("%.1f    %.1f    %.1f \n", str2float(argv[1]), str2float(argv[2]), windChill);
            }
        }

        // format of first argument is not a float
        else if(!validArgumentFormat(argv[1])) {
            printf("First argument [%s] is not a valid float. \n", argv[1]);
            exit(3);
        }

        // format of second argument is not a float
        else if (!validArgumentFormat(argv[2])) {
            printf("Second argument [%s] is not a valid float.\n", argv[2]);
            exit(3);
        }
    }

    // case 4: more than two arguments
    if (argc > 3) {
        printf("Usage: ./chill [arg1] [arg2]\n");
        printf("    [arg1]: (optional) represents a temperature value (Fahrenheit) between -99 and 50 (non-inclusive).\n");
        printf("    [arg2]: (optional) represents a wind  value (MPH) between 0.5 and 231 (inclusive).\n");
        exit(2);
    }
    
    // SUCCESS
    exit(0); 
}

/*
 * printHeaderColumns: prints header columns
*/
void 
printHeaderColumns(void) {
    printf(" Temp   Wind   Chill\n");
    printf("-----  -----  ------\n");
}

/*
 * str2float: convert a string integer to a float
 *
 * string[]: an argument from command line that represents a float
 * assumption: assumes input has format of a valid float
*/
float 
str2float(const char string[]) {
    float argument;
    sscanf(string, "%f", &argument);
    return argument;
}

/*
 * calWindChill: return the wind chill
 *
 * temp: first argument passed from command line (Fahrenheit)
 * wind: second argument passed from the command line (MPH)
*/
float 
calWindChill(int temp, int wind){
    float cal = 35.74 + 0.6215*temp - 35.75*(pow(wind, 0.16)) + 0.4275*temp*(pow(wind, 0.16));
    return cal;
}

/*
 * validArgumentFormat: return true if format string resembles a float
 */
bool 
validArgumentFormat(const char string[]) {
    
    char nextChar;
    int nextInt;
    float checkOneTemp;
    float checkTwoTemp;
    
    int checkOne = sscanf(string, "%f%c", &checkOneTemp, &nextChar);
    int checkTwo = sscanf(string, "%f%d", &checkTwoTemp, &nextInt); 

    if (checkOne == 1 && checkTwo == 1) {
        return true;
    } 
    
    return false;

}

/*
 * isTempInRange: returns true if -99 < temp < 50
 *
 * string[]: first argument (temperature) read from the command line
*/
bool 
isTempInRange(const char string[]) {
    int temp = str2float(string);

    if (temp > -99.0 && temp < 50.0) {
        return true;
    } 
    
    return false;
}

/*
 * isWindInRange: returns true if 0.5 <= wind <= 231 MPH
 * 
 * string[]: second argument (wind velocity) read from the command line
*/
bool 
isWindInRange(const char string[]) {
    int wind = str2float(string);

    if (wind >= 0.5 && wind <= 231) {
        return true;
    }

    return false;
}
