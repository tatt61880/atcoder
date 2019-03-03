use strict;
use warnings;
my ($N, $M) = split / /, <>;
if($M < $N * 2 || $N * 4 < $M){
	print "-1 -1 -1\n";
	exit 0;
}
my $x;
my $y;
my $z;
if($M <= $N * 3){
	$y = $M - $N * 2;
	$x = $N - $y;
	$z = 0;
}else{
	$x = 0;
	$z = $M - $N * 3;
	$y = $N - $z;
}
print "$x $y $z\n";
