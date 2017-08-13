# Example 14.40

($x, $y, $z) = (1, 1, 1);
{
    my ($x, $y) = (2, 2);
    local $z = 3;
    {                               # inner scope
        our ($x, $z);               # use globals
        print "$x, $y, $z\n";
    }
}
