# Example 14.58

$line = <>;
chop $line;                     # delete trailing newline
$line =~ /is/;
print "prefix($`) match($&) suffix($')\n";
