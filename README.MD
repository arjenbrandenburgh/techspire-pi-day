# Pi Day Challenge Program

Welcome to our submission for the **techspire Pi Day Challenge**, where we aim to calculate as many digits of Pi as possible within a 60-second timeframe! This challenge celebrates Pi Day (3/14) in style, and we're thrilled to participate and hopefully win a scrumptious pie.

## About the Challenge

Techspire has thrown down the gauntlet: code up a storm and generate as many digits of Pi as you can in 60 seconds! 🍰 The winning team receives a delicious pie, delivered straight to their office door. The champion will be unveiled on April 11, 2024. Ready for a slice of the action? May the odds be ever in your flavour! 🤓

## Our Approach

Our program is written in C++, utilizing the GNU Multiple Precision Arithmetic Library (GMP) to handle the high-precision arithmetic required for this task. We've chosen the Chudnovsky algorithm for its rapid convergence, allowing us to compute thousands of digits of Pi in the allotted time.

## How to Run the Program

### Prerequisites

Ensure you have the GMP library installed on your system. If you're on Ubuntu, you can install it using:

```bash
sudo apt-get install libgmp3-dev
```

For other operating systems, please refer to the GMP documentation.


### Compilation

Navigate to the program directory and compile the program using the following command:

```bash
g++ -o calculate-pi calculate-pi.cpp -lgmp -lgmpxx -std=c++11
```

### Execution

Run the compiled program with:

```bash
./calculate-pi
```

The program will execute for 60 seconds, attempting to calculate as many digits of Pi as possible within that timeframe. The result will be printed to the terminal.

You can also just refer to the program in the dist folder and run it.
