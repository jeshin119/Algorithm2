#!bin/bash

#test1
./a.out <<EOF
1000000
EOF

./cmp <<EOF
1000000
EOF