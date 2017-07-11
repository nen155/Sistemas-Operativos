#!/bin/bash

tail /tmp/listacores > aux
cat aux > /tmp/listacores
rm aux
