cd ../bin || exit
curr_path=$(pwd)
echo "#define PATH \"$curr_path\""> ../src/path.h