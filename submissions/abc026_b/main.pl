use strict;
use warnings;
my $N = <>;
my @R;
for(1..$N){
	my $r = <>;
	chomp $r;
	push @R, $r;
}
my $ans = 0;
my $i = 0;
foreach my $r(sort {$b <=> $a} @R)
{
	if($i % 2 == 0){
		$ans += $r * $r;
	}else{
		$ans -= $r * $r;
	}
	$i++;
}
$ans *= 3.141592653589793238;
print "$ans\n";
