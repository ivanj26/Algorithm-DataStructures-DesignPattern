read x
read y
read z

if [[ $x == $y && $y == $z ]]; then
    echo "EQUILATERAL"
elif [[ $x == $y || $y == $z ]]; then
    echo "ISOSCELES"
else
    echo "SCALENE"
fi