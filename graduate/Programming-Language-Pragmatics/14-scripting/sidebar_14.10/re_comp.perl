# Sidebar 14.10

@strings = ("now is the time", "this is a string", "hi, mom", "hello, world");
@patterns = ("is", "h.*o", "i.*m");

for (@patterns) {           # iterate over patterns
    my $pat = qr($_);       # compile to automaton
    for (@strings) {        # iterate over strings
        if (/$pat/) {       # no recompilation required
            print;          # print all strings that match
            print "\n";
        }
    }
    print "\n";
}
