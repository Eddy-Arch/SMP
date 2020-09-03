#!/bin/sh
gcc smp.c -o smp

echo "program compiled succsessfully. to install, enter your password."
sudo mv smp /bin/smp

