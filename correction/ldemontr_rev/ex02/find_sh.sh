find . -type f -name "*.sh" -printf '%f\n' | awk -F '.' '{print $1}'
