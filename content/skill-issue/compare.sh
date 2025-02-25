#!/usr/bin/env bash

# --- Compile the solutions and generator ---
g++ -std=c++17 -O2 good.cpp -o good
g++ -std=c++17 -O2 bad.cpp -o bad
g++ -std=c++17 -O2 generator.cpp -o generator

# --- Set the maximum number of tests to run ---
MAX_TESTS=1000

# --- Stress test loop ---
for ((i=1; i<=MAX_TESTS; i++)); do
    echo "Test #$i"
    
    # Generate test case
    ./generator > test_input.txt
    
    # Run the 'good' and 'bad' solutions
    ./good < test_input.txt > good_output.txt
    ./bad < test_input.txt > bad_output.txt
    
    # Compare their outputs
    if ! diff -q good_output.txt bad_output.txt > /dev/null 2>&1; then
        echo "Mismatch found on test #$i!"
        echo "----------------------------------------"
        echo "Input (test_input.txt):"
        cat test_input.txt
        echo "----------------------------------------"
        echo "Expected output (good_output.txt):"
        cat good_output.txt
        echo "----------------------------------------"
        echo "Wrong output (bad_output.txt):"
        cat bad_output.txt
        echo "----------------------------------------"
        exit 1
    fi
done

echo "All $MAX_TESTS tests passed without mismatch."
