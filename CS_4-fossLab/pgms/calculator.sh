
#!/bin/bash

c='y'

while [ $c = 'y' ]
do

	echo "Enter the first number"
	read first
	echo "Enter the second number"
	read second

	echo "Which operation do you want to perform?"
	echo "1.Addition"
	echo "2.Subtraction"
	echo "3.Multiplication"
	echo "4.Division"
	echo "5.Modulus"

	read choice

	case $choice in
		1)	echo "Final answer is :" $(( first + second ));;
		2)      echo "Final answer is :" $(( first - second ));;
		3)      echo "Final answer is :" $(( first * second ));;
		4)      echo "Final answer is :" $(( first / second ));;
		5)      echo "Final answer is :" $(( first % second ));;
		*)	echo " Enter a valid choice";;
	esac

	echo "Continue?(y/n)"
	read c
done
