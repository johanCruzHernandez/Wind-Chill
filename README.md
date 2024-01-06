# Wind Chill Temperature
## Author: Johan Cruz Hernandez
## Programming Language: C
### About:
This is a C program that calculates the wind chill temperature given wind velocity and current temperature as parameters passed in by the user.
### How to run:
- Compile chill.c: ```gcc chill.c -o chill```
### Use Case #1 (no parameters passed): ```./chill```
If the user provides no arguments to your program, it should print out a table of temperatures (from -10 to +40 by 10's) and and wind speeds (from 5 to 15 by 5's).
Your output should look similar to the following, with nice columns and titles:

```bash
$ ./chill
  Temp   Wind  Chill
 -----  -----  -----
 -10.0    5.0  -22.3
 -10.0   10.0  -28.3
 -10.0   15.0  -32.2

   0.0    5.0  -10.5
   0.0   10.0  -15.9
   0.0   15.0  -19.4

  10.0    5.0    1.2
  10.0   10.0   -3.5
  10.0   15.0   -6.6

  20.0    5.0   13.0
  20.0   10.0    8.9
  20.0   15.0    6.2

  30.0    5.0   24.7
  30.0   10.0   21.2
  30.0   15.0   19.0

  40.0    5.0   36.5
  40.0   10.0   33.6
  40.0   15.0   31.8
```

### Use Case #2 (one parameter: temperature) ```./chill 32```
If the user provides one argument, it refers to a temperature (expressed as a floating-point number). You may assume (without checking) the argument is a valid floating-point number. If that temperature is less than 50 and greater than -99, it is acceptable; chill then prints a table of wind speeds (from 5 to 15 by 5's) and the calculated wind chills for that temperature only. Your program's output for one argument should look like this:

```bash
$ ./chill 32
  Temp   Wind  Chill
 -----  -----  -----
  32.0    5.0   27.1
  32.0   10.0   23.7
  32.0   15.0   21.6
```

### Use Case #3 (two parameters: temperature and wind velocity): ```./chill 32 10```
If the user provides two arguments, they refer to be temperature and velocity, respectively (expressed as floating-point numbers).
You may assume (without checking) the arguments are valid floating-point numbers.
The temperature must be less than 50 and greater than -99.
The velocity must be greater than or equal to 0.5.

If the arguments are acceptable, then your program should calculate and print the wind chill for *that temperature and velocity only*.

Your program's output for two arguments should look like this:

```bash
$ ./chill 32.5 10
  Temp   Wind  Chill
 -----  -----  -----
  32.5   10.0   24.3
```

If either argument is out of range, your program should issue a message and exit.
Here's an example:

```bash
$ ./chill 55
./chill: Temperature must be less than or equal to 50.0 degrees Fahrenheit
$ ./chill 10 0
./chill: Wind velocity must be greater than or equal to 0.5 MPH
```

### Files
- chill.c: main program; handles input from the user and returns the wind chill factor given the wind velocity and temperature.
- testing.out: unit tests for chill.c
- testing.sh
