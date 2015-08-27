#!/bin/bash

your_name="qinjx"
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
greeting_2="hello, $your_name !"
str="Hello, I know you are \"$your_name\"!"

array_name=(value0 value1 value2 value3 value4 value5)

echo $greeting 
echo $greeting_1
echo $greeting_2
echo $str
echo ${#str}
echo ${str:1:4}
echo `expr index "$str" you`

echo ${array_name[@]}
echo ${array_name[*]}
echo ${#array_name[@]}
echo ${#array_name[*]}
echo ${#array_name[1]}

echo "Please input your name: "
read name
echo "${name} is great"
echo -e "${name} is great \n"

num1=100
num2=100
if test $num1 -eq $num2
then
	echo "The two numbers is equal!"
else
	echo "The two numbers is not equal!"
fi

if test num1=num2
then
	echo "The two strings are equal!"
else
	echo "The two strings are not equal!"
fi

cd ~/fan/programming/shell/basic
filename="test.sh"
if test -e ./$filename
then
	echo "The file \"${filename}\" already exists!"
else
	echo "The file \"${filename}\" does not exists!"
fi


for num in 1 2 3 4 5 
do
	echo "The value is: $num"
done

int=1
while(($int<=5))
do
	echo $int
	let "int++"
done

echo "please input the data between one and four:"
read case_num
case $case_num in
	1)
		echo "You input the number: ${case_num}!"
	;;
	2)
		echo "You input the number: ${case_num}!"
	;;
	3)
		echo "You input the number: ${case_num}!"
	;;
	4)
		echo "You input the number: ${case_num}!"
	;;
	*)
		echo "The number is wrong!"
	;;
esac

echo -e "\n"
function demoFun(){
	echo "This is the shell function"
}

echo "demoFun begin..."
demoFun
echo "demoFun end!"

echo -e "\n"
function demoFunWithReturn(){
	echo "Please input a number: "
	read data
	echo "Please input another number: "
	read data1
	echo "The sum of two numbers is:"
	return $(($data+$data1))
}

demoFunWithReturn
echo $?

echo -e "\n"
function demoFunWithParam(){
	echo "The value of first parameter is ${1}"
	echo "The value of second parameter is ${2}"
	echo "The value of third parameter is ${3}"
	echo "The value of fifth parameter is ${5}"
	echo "The value of tenth parameter is ${10}"
	echo "The value of eleventh parameter is ${11}"
	echo "The amount of the parameters is $#"
	echo "The string of the patameters is ${*}"
}

demoFunWithParam 1 2 3 4 5 6 7 8 9 10 11 12 

echo "The ID of current process: $$"
echo "The ID of last process in background: $!"



