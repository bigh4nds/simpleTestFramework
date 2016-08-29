#!/bin/bash

# Christopher Finn 2011 ECE373
# Assignment 3: Unix Scripting for Automatic Testing

g++ -o QuadraticSolution QuadraticSolution.cpp	 # Compiles QuadraticSolution.cpp 
for xx in `ls ./testcases/input?.txt`		 # Loops through input files
do
	echo \# Running Testcase $xx		
	cp $xx input.txt			 # Copy current input file to input.txt
	./QuadraticSolution > $xx.out            # Redirect QuadraticSolution output to file
	if diff $xx.out $xx.sol >/dev/null; then # If no differences between output and solution
	echo \## Result Matches $xx.sol		 # then the result matches expected result
	else
		echo \## Difference in output from $xx.sol  # If not then display
		diff $xx.out $xx.sol			    # the differences
	fi
done

