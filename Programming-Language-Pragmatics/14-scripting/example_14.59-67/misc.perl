# Perl code from Examples 14.59 through 14.64

$a = "4";
print $a . 3 . "\n";            # 43 ('.' is concatenation)
print $a + 3 . "\n";            #  7 ('+' is addition)


$a[3] = "1";                    # (array @a was previously undefined)
print $a[3] + $a[4], "\n";      # 1

@colors = ("red", "green", "blue");     # initializer syntax
print $colors[1];                       # green
print "\n";

%complements = ("red" => "cyan",
                "green" => "magenta", "blue" => "yellow");
print $complements{"blue"};             # yellow
print "\n";
