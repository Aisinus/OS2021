for i in $(seq 1000) ; do 
    addNumber=$(cat file | tail -n 1)
    ((addNumber++))
    echo "$addNumber" >> file
done