" Examples 10.71 - 10.76
|
| Note that GNU Smalltalk syntax differs from that used in the book.
| In particular, assignment uses :=
| Note also that:
|   Comments are double-quoted strings.
|   The printNl message is the standard way to make an object print itself.
"

n := -5.
n < 0
    ifTrue: [abs := n negated]
    ifFalse: [abs := n].
abs printNl.

pow := 1.
10 timesRepeat:
    [pow := pow * n].
pow printNl.

a := Array new: 100.
1 to: 100 do:
    [:i | a at: i put: i].
sum := 0.
1 to: 100 by: 2 do:
    [:i | sum := sum + (a at: i)].
sum printNl.

b := [n := n + 1].          "b is now a closure"
c := [:i | n := n + i].     "so is c"
b value.                    "increment n by 1"
n printNl.
c value: 3.                 "increment n by 3"

"------------------------------------------------------"
" Declarations for a very simple linked list class "
"------------------------------------------------------"
Object subclass: #Node
    instanceVariableNames: 'value next'
    classVariableNames: ''
    poolDictionaries: ''
    category: nil !
!Node class methodsFor: ''!
new |n|
    n := super new.
    n init.
    ^n
!!
!Node methodsFor: ''!
init
    value := nil.
    next := nil
!
value
    ^value
!
value: v
    value := v
!
next
    ^next
!
next: n
    next := n
!!
"------------------------------------------------------"

myList := Node new.
myList value printNl.

cursor := myList.
1 to: 3 do:
    [:i |
        n := Node new.
        n value: i.
        cursor next: n.
        cursor := n
    ].

tail := myList.
[tail next ~~ nil]
    whileTrue: [tail := tail next].
tail value printNl.

"------------------------------------------------------"
" Declarations for a very simple binary tree class "
"------------------------------------------------------"
Object subclass: #Tree
    instanceVariableNames: 'value left right'
    classVariableNames: ''
    poolDictionaries: ''
    category: nil !
!Tree class methodsFor: ''!
new |t|
    t := super new.
    t init.
    ^t
!!
!Tree methodsFor: ''!
init
    value := nil.
    left := nil.
    right := nil.
!
value
    ^value
!
value: v
    value := v
!
left
    ^left
!
left: l
    left := l
!
right
    ^right
!
right: r
    right := r
!
inorderDo: b
    (left ~~ nil)
        ifTrue: [left inorderDo: b].
    b value: self.
    (right ~~ nil)
        ifTrue: [right inorderDo: b]
!!
"------------------------------------------------------"

myTree := Tree new.
myTree value: 2.
l := Tree new.
r := Tree new.
l value: 1.
r value: 3.
myTree left: l.
myTree right: r.
myTree inorderDo: [:node | node value printNl].

"------------------------------------------------------"

!SmallInteger methodsFor: ''!
gcd: other                          "other is a formall parameter"
    (self = other)
        ifTrue: [^self].            "end condition"
    (self < other)
        ifTrue:  [^self gcd: (other - self)]    "recurse"
        ifFalse: [^other gcd: (self - other)]   "recurse"
!!

(48 gcd: 36) printNl.               "12"
