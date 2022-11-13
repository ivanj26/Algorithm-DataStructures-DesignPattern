# Your task is to use for loops to display only odd natural numbers from 1 to 99.
# only ODD Number(s)

for i in {1..99}
do
    if [ $((i % 2)) == 1 ]; then
        echo $i
    fi
done