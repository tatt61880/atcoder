use strict;
use warnings;
<>;
while(<>){
	my $str = $_;
	my $ans = $str =~ s/tokyo//g;
	$ans += $str =~ s/kyoto//g;
	print "$ans\n";
}
