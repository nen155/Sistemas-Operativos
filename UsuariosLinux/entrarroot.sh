#!/bin/bash

cp /fenix/depar/lsi/UML/*.gz /tmp
gunzip /tmp/*.gz
./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=1024m
