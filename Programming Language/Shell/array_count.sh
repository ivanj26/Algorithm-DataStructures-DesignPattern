while read line
do
    lines=("${lines[@]}" "$line")
done

echo "${#lines[@]}"