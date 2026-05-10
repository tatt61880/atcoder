use strict;
use warnings;

my $buf = <>;
chomp $buf;

$buf =~ s/eraser//g;
$buf =~ s/erase//g;
$buf =~ s/dreamer//g;
$buf =~ s/dream//g;
if($buf eq ""){
	print "YES\n";
}else{
	print "NO\n";
}
