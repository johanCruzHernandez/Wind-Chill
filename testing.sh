#!bin/bash

# compile the program
# mygcc chill.c -o chill_test

# case 1: no arguments
./chill > output_1a.txt
echo "Test Case 1a: No arguments."
cat output_1a.txt


# case 2: one argument
# valid argument
./chill 32 > output_2a.txt
echo "Test Case 2a: One argument."
cat output_2a.txt


./chill 32.0 > output_2b.txt
echo "Test Case 2b: One argument"
cat output_2b.txt


# invalid format (leading character)
./chill a32 > output_2c.txt
echo "Test Case 2c: invalid argument"
cat output_2c.txt


# invalid format (trailing character)
./chill 32a > output_2d.txt
echo "Test Case 2d: invalid argument"
cat output_2d.txt



# temperature out of bounds (lower bound)
./chill -100 > output_2e.txt
echo "Test Case 2e: invalid argument (out of bounds)"
cat output_2e.txt



#temperature out of bounds (higher bound)
./chill 51 > output_2f.txt
echo "Test Case 2f: invalid argument (out of bounds)"
cat output_2f.txt


# case 3: two arguments
# valid argument
./chill 32 100 > output_3a.txt
echo "Test Case 3a: two invalid arguments"
cat output_3a.txt

./chill 32.0 100 > output_3b.txt
echo "Test Case 3b: two valid arguments"
cat output_3b.txt

./chill 32. 100. > output_3c.txt
echo "Test Case 3c: two valid arguments"
cat output_3c.txt

# invalid format (leading character)
./chill a32 100 > output_3d.txt
echo "Test Case 3d: first argument invalid"
cat output_3d.txt


./chill 32 a100 > output_3e.txt
echo "Test Case 3e: second argument invalid"
cat output_3e.txt


./chill a32 a100 > output_3f.txt
echo "Test Case 3f: both arguments are invalid"
cat output_3f.txt

# invalid format (trailing character)
./chill 32a 100 > output_3g.txt
echo "Test Case 3g: invalid first argument"
cat output_3g.txt

./chill 32 100a > output_3h.txt
echo "Test Case 3h: invalid secong argument"
cat output_3h.txt

./chill 32a 100a > output_3i.txt
echo "Test Case 3i: both arguments invalid"
cat output_3i.txt

# temperature out of bounds (lower bound)
./chill -100 100 > output_3j.txt
echo "Test Case 3j: first argument out of bounds"
cat output_3j.txt

# temperature out of bounds (higher bound)
./chill 51 100 > output_3k.txt
echo "Test Case 3k: second argument out of bounds"
cat output_3k.txt

# wind velocity out of bounds (lower bound)
./chill 32 0.4 > output_3l.txt
echo "Test Case 3l: second argument out of bounds (lower)"
cat output_3l.txt

./chill 32 232 > output_3m.txt
echo "Test Case 3m: second argument out of bounds (higher)"
cat output_3m.txt

# # case 4: more than two arguments
./chill 20 100 10  > output_4a.txt
echo "Test Case 4a: too many arguments are passed"
cat output_4a.txt

./chill 20 100 a > output_4b.txt
echo "Test Case 4b: too many arguments are passed in"
cat output_4b.txt
