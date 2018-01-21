use strict;
use warnings;
local $_ = <>;
chomp;
my ($N, $K) = split / /;
local $_ = <>;
chomp;
my @R = split / /;
@R = sort {$a <=> $b} @R;
my $ans = 0;
for my $i(($N - $K)..($N - 1)){
	$ans = ($ans + $R[$i]) / 2;
}
print "$ans\n";
