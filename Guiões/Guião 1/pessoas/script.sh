#!/bin/bash

for ((i=1; i<=$1; i++))
do
IDADE=$(((RANDOM % 100)+1))
echo "./pessoas -i Pessoas${i} $IDADE"
./pessoas -i Pessoas${i} $IDADE
done