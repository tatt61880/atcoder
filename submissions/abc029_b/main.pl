use strict;
use warnings;

my $count = 0;
while(<>){
	my $n = $_ =~ s/r//g;
	$count++ if($n ne "");
}
print "$count\n";
