# Examples 14.70 and 14.71

$time = gmtime;
print $time, "\n";
@time_array = gmtime;
for (@time_array) {
    print;
    print "  ";
}
print "\n";

sub bad_if_array {
    @rtn = ();
    return @rtn;
}
sub bad_if_scalar {
    return undef;
}
sub bad_if_either {
    return wantarray ? () : undef;
}

@foo = bad_if_array;
if (@foo == nil) {
    print "\@foo is nil\n";
} else {
    print "\@foo is not nil\n\telements: ";
    for (@foo) {
        print "[";
        if (defined $_) {
            print;
        } else {
            print "undef";
        }
        print "] ";
    }
    print "\n";
}

@foo = bad_if_scalar;
if (@foo == nil) {
    print "\@foo is nil\n";
} else {
    print "\@foo is not nil\n\telements: ";
    for (@foo) {
        print "[";
        if (defined $_) {
            print;
        } else {
            print "undef";
        }
        print "] ";
    }
    print "\n";
}

@foo = bad_if_either;
if (@foo == nil) {
    print "\@foo is nil\n";
} else {
    print "\@foo is not nil\n\telements: ";
    for (@foo) {
        print "[";
        if (defined $_) {
            print;
        } else {
            print "undef";
        }
        print "] ";
    }
    print "\n";
}

$foo = bad_if_array;
if (defined $foo) {
    print "\$foo is defined ($foo)\n";
} else {
    print "\$foo is not defined\n";
}

$foo = bad_if_scalar;
if (defined $foo) {
    print "\$foo is defined ($foo)\n";
} else {
    print "\$foo is not defined\n";
}

$foo = bad_if_either;
if (defined $foo) {
    print "\$foo is defined ($foo)\n";
} else {
    print "\$foo is not defined\n";
}
