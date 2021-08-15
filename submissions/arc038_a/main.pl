use strict;
use warnings;

my $N = <>;
my @A = split / /, <>;

my $sumA = 0;
my $sumB = 0;

my $turn = 1;
foreach(sort {$b <=> $a} @A){
	if($turn){
		$sumA += $_;
	}else{
		$sumB += $_;
	}
	$turn = !$turn;
}
printf("$sumA\n");
