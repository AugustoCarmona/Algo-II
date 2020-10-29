#read input
file_name=$1
printf "\n"
gcc $file_name.c -o $file_name && ./$file_name
printf "\n"
