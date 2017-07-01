# Examples 14.72 (Figure 14.19), 14.73, 14.74, and 14.75

{   package Integer;

    sub new {
        my $class = shift;      # probably "Integer"
        my $self = {};          # reference to new hash
        bless($self, $class);
        $self->{val} = (shift || 0);
        return $self;
    }
    sub set {
        my $self = shift;
        $self->{val} = shift;
    }
    sub get {
        my $self = shift;
        return $self->{val};
    }
}

$c1 = Integer->new(2);          # Integer::new("Integer", 2)
$c2 = new Integer(3);           # alternative syntax
$c3 = new Integer;              # no initial value specified

print $c1->get, " ", $c2->get, " ", $c3->get, " ", "\n";
$c1->set(4);
$c2->set(5);
$c3->set(6);
print $c1->get, " ", $c2->get, " ", $c3->get, " ", "\n";

{   package Tally;
    # @ISA = ("Integer");
    use base ("Integer");       # preferred syntax

    sub inc {
        my $self = shift;
        $self->{val}++;
    }
}

$t1 = new Tally(3);
$t1->inc;
$t1->inc;
print $t1->get, "\n";           # prints 5

