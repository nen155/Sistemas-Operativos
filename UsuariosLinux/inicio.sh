#!/bin/bash

 # -*- ENCODING: UTF-8 -*-
 
 cp /fenix/depar/lsi/UML/*.gz /tmp
 gunzip *.gz
 cd /tmp
 chmod +x kernel32-3.0.4
 ./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=1024m
