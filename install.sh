#!/bin/sh
gcc smp.c -o smp

clear; echo "program compiled succsessfully. to install, enter your password."
sudo mv smp /bin/smp

