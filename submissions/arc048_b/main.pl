use strict;
use warnings;

my $num = <>;
my %rateCount;
my %rateRank;
my %count;
my @data;

while(<>)
{
	chomp;
	m|^(\d+)|;
	my $r = $1;
	$count{$_}++;
	$rateCount{$r}++;
	push @data, $_;
}

sub f($);
my $c = 1;
foreach my $r(sort {$b <=> $a}(keys %rateCount)){
	$rateRank{$r} = $c;
	$c += $rateCount{$r};
}

for
each(@data)
{
	m|(\d+) (\d+)|;
	my $r = $1;
	my $h = $2;
	my $lh = (3 + $h - 2) % 3 + 1;
	#print "[$r $lh]";
	my $lose = $rateRank{$r} - 1;
	$lose += $count{"$r $lh"} if(defined $count{"$r $lh"});
	my $draw = $count{$_} - 1;
	my $win = $num - $lose - $draw - 1;
	print "$win $lose $draw\n";
}
