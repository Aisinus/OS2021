for i in $(seq 1000) ; do
    while : ; do
        if ln file1 file1.lock > "/dev/null" 2>&1 ; then
            break
        fi
        sleep 0.001
    done
    addNumber=$(cat file1 | tail -n 1)
    ((addNumber++))
    echo "$addNumber" >> file1
    rm file1.lock
done