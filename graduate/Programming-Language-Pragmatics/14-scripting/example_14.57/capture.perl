#! /usr/bin/perl
# Example 14.57
# Accepts FP constants on standard input.  Type ^D to quit.

while (<>) {
    $line = $_;
    if (/^([+-]?)((\d+)\.|(\d*)\.(\d+))(e([+-]?\d+))?$/) {
        # floating point number
        print "sign:     ", $1, "\n";
        print "integer:  ", $3, $4, "\n";
        print "fraction: ", $5, "\n";
        print "mantissa: ", $2, "\n";
        print "exponent: ", $7, "\n";
    }
}
