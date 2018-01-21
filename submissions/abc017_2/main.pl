use strict;
use warnings;
my $S = <>;
chomp $S;
$S =~ s/ch//g;
$S =~ s/o|k|u//g;
if($S eq ""){
	print "YES\n";
}else{
	print "NO\n";
}
