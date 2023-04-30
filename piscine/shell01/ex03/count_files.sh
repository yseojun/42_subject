find . -type d -o -type f | wc -l | awk '{ print $1 }'
