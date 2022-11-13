while read line
do
    Array=("${Array[@]}" "$line")
done

# Filter out the array
# Only print out the elements that does not have a or A
echo ${Array[@]/*[aA]*/}