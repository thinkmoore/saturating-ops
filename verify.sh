#!/bin/bash

mkdir verify-tmp &> /dev/null
if [ $? -ne 0 ]; then
    echo "verify-tmp already exists, aborting..."
    exit
fi

mkdir -p verify-logs

for i in `seq 0 4`;
do
    echo -n "Attempting to verify ARITHTYPE ${i}... "
    frama-c -cpp-extra-args="-DARITHTYPE=${i}" -pp-annot -rte sat_ops.c -then -wp -wp-out verify-tmp -wp-prover z3 &> "verify-logs/${i}.log"
    if grep "Proved" "verify-logs/${i}.log" | awk '{print ($4 == $6 ? "yes" : "no")}' | grep "yes" &> /dev/null; then
	echo "yes."
    else
	echo "no."
    fi
done

rm -Rf verify-tmp
