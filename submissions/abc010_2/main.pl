use strict;
use warnings;

<>;
my @A = split / /, <>;

#123456789A
#oxooxooxoo
#oxoxoxoxox
#o-o---o-o-
my $count = 0;
foreach(@A){
	if($_ == 2){
		$count++;
	}elsif($_ == 4){
		$count++;
	}elsif($_ == 5){
		$count+=2;
	}elsif($_ == 6){
		$count+=3;
	}elsif($_ == 8){
		$count++;
	}elsif($_ == 10){

		$count++;
	}
}
print "$count\n";
