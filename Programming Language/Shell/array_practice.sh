# Replace first capital letter for each element with dot character
while read line
do
    array=("${array[@]}" ".${line:1}")
done

echo "${array[@]}"