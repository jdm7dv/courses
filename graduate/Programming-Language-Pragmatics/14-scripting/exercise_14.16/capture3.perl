#! /usr/bin/perl
# Exercise 14.16
# Accepts FP constants on standard input.  Type ^D to quit.

while (<>) {
    $line = $_;
    if (/^([+-]?)((\d+)\.|(\d*)\.(\d+))(?:e([+-]?\d+))?$/) {
        # floating point number
        print "sign:     ", $1, "\n";
        print "integer:  ", $3, $4, "\n";
        print "fraction: ", $5, "\n";
        print "mantissa: ", $2, "\n";
        print "exponent: ", $6, "\n";           # not $7
    }
}
