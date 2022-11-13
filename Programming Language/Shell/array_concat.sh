array=($(cat))

# triple array into one array
arrays=("${array[@]}" "${array[@]}" "${array[@]}")
echo "${arrays[@]}"