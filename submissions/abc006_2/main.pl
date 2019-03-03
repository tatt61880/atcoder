use strict;
use warnings;
my $N = <>;
my @A;
push @A, 0;
push @A, 0;
push @A, 1;
for my $i(3 .. $N)
{
	$A[$i] = ($A[$i - 1] + $A[$i - 2] + $A[$i - 3]) % 10007;
}
print "$A[$N - 1]\n";
