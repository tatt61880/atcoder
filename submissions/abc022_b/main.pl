use strict;
use warnings;

<>;

my %A;
my $count = 0;
while(<>){
	chomp;
	if(defined $A{$_}){
		$count++;
	}else{
		$A{$_} = 1;
	}
}

print "$count\n";
