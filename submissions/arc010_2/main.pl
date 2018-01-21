use strict;
use warnings;
<>;
my @holidays;
while(<>){
	chomp;
	m|(.*)/(.*)|;
	push @holidays, [$1, $2];
}
sub sort_func($);
@holidays = sort sort_func(@holidays);
my $max = 0;
my $count = 0;
my $day = 1;
my $stock = 0;
for my $m(1..12){
	for my $d(1..31){
		last if($m == 2 && $d == 30);
		last if($m =~ m/4|6|9|11/ && $d == 31);
		if(@holidays && $m == $holidays[0][0] && $d == $holidays[0][1]){
			shift @holidays;
			$stock++;
		}
		if($day % 7 < 2 || $stock > 0){
			$stock-- unless($day % 7 < 2);
			$count++;
			$max = $count if($count > $max);
		}else{
			$count = 0;
		}
		$day++;
	}
}
print "$max\n";
sub sort_func($)
{
	if($a->[0] <=> $b->[0]){
		return $a->[0] <=> $b->[0];
	}else{
		return $a->[1] <=> $b->[1];
	}
}
