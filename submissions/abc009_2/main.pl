use strict;
use warnings;

<>;
my @A;

while(<>){
	chomp;
	push @A, $_;
}

my $max = "";
for(reverse sort {$a <=> $b} @A){
	if($max eq ""){
		$max = $_;
	}elsif($max ne $_) {
		print "$_\n";
		exit 0;
	}
}
