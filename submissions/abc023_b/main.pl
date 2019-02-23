use strict;
use warnings;

my $N = <>;
if($N % 2 == 0){
	print "-1\n";
	<>; #一応入力を捨てておこう。
}else{
	my $S = <>;
	chomp $S;

	my $A = "b";
	for(1..($N / 2)){
		if($_ % 3 == 1){
			$A = "a" . $A . "c";
		}elsif($_ % 3 == 2){
			$A = "c" . $A . "a";
		}else{
			$A = "b" . $A . &#3
4;b";
		}
	}
	if($A eq $S){
		my $n = int ($N / 2);
		print "$n\n";
	}else{
		print "-1\n";
	}
}
