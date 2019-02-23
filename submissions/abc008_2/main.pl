use strict;
use warnings;

<>;
my %S;

my $max = 0;
my $ans;
while(<>){
	if(defined $S{$_}){
		$S{$_}++;
	}else{
		$S{$_} = 1;
	}
	if($S{$_} > $max){
		$ans = $_;
		$max = $S{$_};
	}
}
print "$ans";
