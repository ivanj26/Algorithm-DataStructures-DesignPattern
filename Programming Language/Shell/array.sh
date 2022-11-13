# Print all elements in array
while read country
do
    countries=("${countries[@]}" "$country")
done

echo "${countries[@]}"

# Print portion of array
# Print only third element until seventh element
while read country
do
    countries=("${countries[@]}" "$country")
done

# Start: 3rd element
# Length: 5 (3th,4th,5th,6th,7th)
echo "${countries[@]:3:5}"

# Print a specified element in array
# 3rd index
array=($(cat))
echo "${array[3]}"