#!/bin/bash

if [ ! -d "build/tests" ] ; then
		echo "Error: Test directory does not exist. Run 'make tests' first."
		exit
fi

echo "Running tests in test directory"

for t in "build/tests"/* ; do
		if [ -x ${t} ] ; then
				echo "--Testing $t--"
				./$t
		fi
done

exit
