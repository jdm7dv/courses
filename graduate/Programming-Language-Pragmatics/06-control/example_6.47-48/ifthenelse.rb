# Example 6.47

ARGV.length() == 1 or begin
    $stderr.print("usage: #{$0} value\n"); exit(1)
end
a = ARGV[0].to_i()      # convert string argument to integer

b = 2
c = 3
d = 5

if a == b then
    print "matches b\n"
elsif a == c then
    print "matches c\n"
elsif a == d then
    print "matches d\n"
else
    print "doesn't match\n"
end
