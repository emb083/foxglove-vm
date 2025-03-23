# No shebang, not planning on running this file
# Just examples

### Int comparisons

[ 3 -ge 2 ] # greater than or equal to
(( 5 >= 3 ))    # note the parentheses

[ 3 -gt 2 ] # greater than
(( 5 > 3 ))

[ 5 -le 10 ] # less than or equal to
(( 5  <= 10 ))

[ 5 -lt 10 ] # less than
(( 5 < 3 ))

[ 5 -eq 5 ] # equal to
# no == operator for ints

[ 5 -ne 5 ] # not equal to
# != (exists? yes or no? probably no?) for integers


### String Comparisons

# equality - == for pattern matching and literal matching
[ "apple" == "apple" ]  # returns True

myvar="hi you"
[ $myvar == "hi you" ]  # returns False
                    # since hi you has a space in it, the single brackets cause word splitting

[[ $myvar == "hi you" ]] # returns True

# checking for alphabetical order with ASCII and < and >
[[ "apple" < "banana" ]] # returns True
[ "apple" \< "banana" ]


# check for empty string with -z
avar=""
[ -z $avar ] # returns True

# check if a string is not null/empty
[ -n $avar ] # returns false here