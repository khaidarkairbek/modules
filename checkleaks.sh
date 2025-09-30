#!/bin/bash


if [ ! -d "build/tests" ] ; then
		echo "Error: Test directory does not exist. Run 'make tests' first."
		exit
fi

echo "Running Valgrind leak check on tests in test directory"

for t in "build/tests"/* ; do
		if [ -x ${t} ] ; then
				echo "Testing $t"
				valgrind --leak-check=full "$t" > "$t.valgrind.log" 2>&1

				if grep -q "no leaks are possible" ${t}.valgrind.log; then
						echo "$t passed"
				else
						echo "$t has memory leaks"
						exit
				fi
		fi
done

echo "All tests passed with no leaks!"
				
