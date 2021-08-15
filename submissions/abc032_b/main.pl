use strict;
use warnings;

my $s = <>;
chomp $s;
my $len = length $s;
my $k = <>;

my %dict;
my $count = 0;
for(0..$len - $k){
	my $sub = substr $s, $_, $k;
	if(defined $dict{$sub}){
	}else{
		$dict{$sub} = 0;
		$count++;
	}
}
print "$count\n";
