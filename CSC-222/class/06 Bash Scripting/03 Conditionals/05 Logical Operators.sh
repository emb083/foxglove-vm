# no shebang, not to be run

# and
[ 1 -eq 1 -a 2 -eq 2 ]  # 1==1 AND 2==2 (returns True)
[[ 1 -eq 1 && 2 -eq 2 ]]    # can use && if double brackets
[ 1 -eq 1 ] && [ 2 -eq 2 ] # all return True

# or
[ 1 -eq 1 -o 2 -eq 2 ]
[[ 1 -eq 1 || 2 -eq 2 ]]
[ 1 -eq 1 ] || [ 2 -eq 2 ]

# not - !