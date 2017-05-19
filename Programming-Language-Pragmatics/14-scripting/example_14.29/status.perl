#! /usr/bin/perl
# Example 14.29 (Figure 14.10)

# To work, this file must be placed in a special directory known to the
# local web server, typically named "cgi-bin".  Generally this directory
# is writable only by privileged users, and the programs it contains run
# with the (very limited) privileges of the web server.  You may therefore
# have difficulty testing this code on a shared machine.  On a mac (where
# I tested this), the directory is /Library/WebServer/CGI-Executables,
# which is writable only by users with administrator access.

print "Content-type: text/html\n\n";
print "<!DOCTYPE html>\n";
print "<html lang=\"en\">\n";

$host = `hostname`; chop $host;
print "<head>\n";
print "<meta charset=\"utf-8\" />\n";
print "<title>Status of ", $host, "</title>\n";
print "</head>\n<body>\n";
print "<h1>", $host, "</h1>\n";
print "<pre>\n", `uptime`, "\n", `who`;
print "</pre>\n</body>\n</html>\n";
