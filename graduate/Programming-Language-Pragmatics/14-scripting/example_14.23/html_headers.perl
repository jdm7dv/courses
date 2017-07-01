# Example 14.23 (Figure 14.4)
# usage: perl html_headers.perl test.html

while (<>) {
    next if !/<[hH][123]>/;
    while (!/<\/[hH][123]>/) { $_ .= <>; }
    s/.*?(<[hH][123]>.*?<\/[hH][123]>)//s;
    print $1, "\n";
    redo unless eof;
}
