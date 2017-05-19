#! /usr/bin/perl
# Example 14.30 (Figure 14.11)

# To work, this file must be placed in a special directory known to the
# local web server, typically named "cgi-bin".  Generally this directory
# is writable only by privileged users, and the programs it contains run
# with the (very limited) privileges of the web server.  You may therefore
# have difficulty testing this code on a shared machine.  On a mac (where
# I tested this), the directory is /Library/WebServer/CGI-Executables,
# which is writable only by users with administrator access.

use CGI qw(:standard);      # provides access to CGI input fields
$argA = param("argA");  $argB = param("argB");  $sum = $argA + $argB;

print "Content-type: text/html\n\n";

print "<!DOCTYPE html>\n<html lang=\"en\">\n";
print "<head><meta charset=\"utf-8\" /><title>Sum</title></head>\n<body>\n";
print "<p>$argA plus $argB is $sum</p>\n";
print "</body>\n</html>\n";
