use strict;
use warnings;

my $T = <>;
my $N = <>;
my @A = split / /, <>;
my $M = <>;
my @B = split / /, <>;

my $ans = "yes\n";

while(@B)
{
	shift @A while(@A && @B && $A[0] < $B[0] - $T);
	if(@A == 0 || $A[0] > $B[0]){ # たこ焼きが尽きた。あるいは客を待たせてしまう。
		print "no\n";
		exit 0;
	}
	#たこ焼きを売る
	shift @A;
	shift @B;
}

print "yes\n";
