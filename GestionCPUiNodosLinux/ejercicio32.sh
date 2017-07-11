#!/bin/bash
i=0
k=1
while [ $i -le $1 ]; do
k=$(( $k * $i ))
let i=$i+1
done
echo "el valor de la variable es:$1"
