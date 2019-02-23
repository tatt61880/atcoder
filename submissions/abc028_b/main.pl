use strict;
use warnings;

my $S = <>;
foreach(split //, "ABCDEF"){
	my $count = $S =~ s/$_//g;
	$count = 0 if($count eq "");
	print "$count";
	if($_ eq "F"){
		print "\n";
	}else{
		print " ";
	}
}
