cat  /etc/passwd | cut -d ':' -f 1 | rev | tr '\n' ',' |  tr -d '#' 
