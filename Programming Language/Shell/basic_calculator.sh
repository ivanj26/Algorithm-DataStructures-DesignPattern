read eqn

# print result of given equation
printf "%.3f" $(echo $eqn | bc -l)