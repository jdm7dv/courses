# Exercise 14.17

# usage: sed -f html_headers.sed test.html

# label (target for branch):
:top
/<[hH][123]>.*<\/[hH][123]>/ {      ;# match whole heading
    h                               ;# save copy of pattern space
    s/^.*\(<[hH][123]>\)/\1/        ;# delete text before opening tag
    s/\(<\/[hH][123]>\).*$/\1/      ;# delete text after closing tag
    p                               ;# print what remains
    g                               ;# retrieve saved pattern space
    s/^.*<\/[hH][123]>//            ;# delete through closing tag
    b top
}                                   ;# and branch to top of script
/<[hH][123]>/ {                     ;# match opening tag (only)
    N                               ;# extend search to next line
    b top
}                                   ;# and branch to top of script
d                                   ;# if no match at all, delete
