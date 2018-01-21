use strict;
use warnings;
<>;
my $sumT = 0;
my $sumA = 0;
while(<>)
{
	$sumT += $_ =~ s/R//g;
	$sumA += $_ =~ s/B//g;
}
if($sumA == $sumT){
	print "DRAW\n";
}elsif($sumA > $sumT){
	print "AOKI\n";
}else{
	print "TAKAHASHI\n";
}
