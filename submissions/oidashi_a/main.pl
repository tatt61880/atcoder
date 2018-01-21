use strict;
use warnings;
my $buf;
$buf = <>; chomp $buf;
my ($R, $C) = split / /, $buf;
my ($Sx, $Sy);
my ($Gx, $Gy);
my @maze;
for(0 .. $R - 1){
	$buf = <>; chomp $buf;
	push @maze, [split //, $buf];
}
for my $y(0 .. $R - 1){
	for my $x(0 .. $C - 1){
		if($maze[$y][$x] eq 'S'){
			$Sx = $x;
			$Sy = $y;
			$maze[$y][$x] = '.';
		}elsif($maze[$y][$x] eq 'G'){
			$Gx = $x;
			$Gy = $y;
			$maze[$y][$x] = '.';
		}
	}
}
my @queue;
push @queue, [$Sx, $Sy];
$maze[$Sy][$Sx] = 1;
while(@queue)
{
	my $x = $queue[0][0];
	my $y = $queue[0][1];
	#print "[$x, $y]\n";
	if($y > 0      && $maze[$y - 1][$x] eq '.') {$maze[$y - 1][$x] = $maze[$y][$x] + 1; push @queue, [$x, $y - 1]}
	if($y < $R - 1 && $maze[$y + 1][$x] eq '.') {$maze[$y + 1][$x] = $maze[$y][$x] + 1; push @queue, [$x, $y + 1]}
	if($x > 0      && $maze[$y][$x - 1] eq '.') {$maze[$y][$x - 1] = $maze[$y][$x] + 1; push @queue, [$x - 1, $y]}
	if($x < $C - 1 && $maze[$y][$x + 1] eq '.') {$maze[$y][$x + 1] = $maze[$y][$x] + 1; push @queue, [$x + 1, $y]}
	shift @queue;
}
push @queue, [$Gx, $Gy];
$maze[$Gy][$Gx] = -1;
while(@queue)
{
	my $x = $queue[0][0];
	my $y = $queue[0][1];
	#print "[$x, $y]\n";
	if($y > 0      && $maze[$y - 1][$x] eq '.') {$maze[$y - 1][$x] = $maze[$y][$x] - 1; push @queue, [$x, $y - 1]}
	if($y < $R - 1 && $maze[$y + 1][$x] eq '.') {$maze[$y + 1][$x] = $maze[$y][$x] - 1; push @queue, [$x, $y + 1]}
	if($x > 0      && $maze[$y][$x - 1] eq '.') {$maze[$y][$x - 1] = $maze[$y][$x] - 1; push @queue, [$x - 1, $y]}
	if($x < $C - 1 && $maze[$y][$x + 1] eq '.') {$maze[$y][$x + 1] = $maze[$y][$x] - 1; push @queue, [$x + 1, $y]}
	shift @queue;
}
my $max = 0;
for my $y(0 .. $R - 1){
	for my $x(0 .. $C - 1){
		if($maze[$y][$x] eq '#'){
			my $m = 0;
			my $M = 0;
			my $p;
			$$p = ($p = \($maze[$y][$x - 1] > 0 ? $M : $m), $$p == 0) || abs $$p > abs $maze[$y][$x - 1] ? $maze[$y][$x - 1] : $$p if($x > 0      && $maze[$y][$x - 1] !~ m/#|\./);
			$$p = ($p = \($maze[$y][$x + 1] > 0 ? $M : $m), $$p == 0) || abs $$p > abs $maze[$y][$x + 1] ? $maze[$y][$x + 1] : $$p if($x < $C - 1 && $maze[$y][$x + 1] !~ m/#|\./);
			$$p = ($p = \($maze[$y - 1][$x] > 0 ? $M : $m), $$p == 0) || abs $$p > abs $maze[$y - 1][$x] ? $maze[$y - 1][$x] : $$p if($y > 0      && $maze[$y - 1][$x] !~ m/#|\./);
			$$p = ($p = \($maze[$y + 1][$x] > 0 ? $M : $m), $$p == 0) || abs $$p > abs $maze[$y + 1][$x] ? $maze[$y + 1][$x] : $$p if($y < $R - 1 && $maze[$y + 1][$x] !~ m/#|\./);
			if($m < 0 && $M > 0){
				my $val = $M - $m;
				$max = $val if($val > $max);
			}
		}
	}
}
print "$max\n";
