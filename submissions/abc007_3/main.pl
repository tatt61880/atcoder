use strict;
use warnings;
my ($R, $C) = split / /, <>;
my ($Sx, $Sy) = split / /, <>;
my ($Gx, $Gy) = split / /, <>;
my @maze;
for(0 .. $R - 1)
{
	push @maze, [split //, <>];
}
my @queue;
push @queue, [$Sx - 1, $Sy - 1];
$maze[$Sx - 1][$Sy - 1] = 0;
while(@queue)
{
	my $x = $queue[0][0];
	my $y = $queue[0][1];
	#print "[$x, $y]\n";
	if($maze[$x][$y - 1] eq '.') {$maze[$x][$y - 1] = $maze[$x][$y] + 1; push @queue, [$x, $y - 1]}
	if($maze[$x][$y + 1] eq '.') {$maze[$x][$y + 1] = $maze[$x][$y] + 1; push @queue, [$x, $y + 1]}
	if($maze[$x - 1][$y] eq '.') {$maze[$x - 1][$y] = $maze[$x][$y] + 1; push @queue, [$x - 1, $y]}
	if($maze[$x + 1][$y] eq '.') {$maze[$x + 1][$y] = $maze[$x][$y] + 1; push @queue, [$x + 1, $y]}
	shift @queue;
}
print $maze[$Gx - 1][$Gy - 1] . "\n";
