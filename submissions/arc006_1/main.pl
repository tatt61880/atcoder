use strict;
use warnings;

my @E = split / /, <>;
my $B = <>;
chomp $B;
my @L = split / /, <>;

my %E;
foreach(@E){
	chomp;
	$E{$_} = 1;
}

my $count = 0;
foreach(@L){
	chomp;
	$count++ if(defined $E{$_});
}

if($count == 6){
	print "1\n";
}elsif($count == 5){
	my $is_bonus = 0;
	foreach(@L){
		$is_bonus = 1 if($_ == $B);
	}
	if($is_bonus){
		print "2\n";
	}else{
		print "3\n";
	}
}elsif($count == 4){
	print "4\n";
}elsi
f($count == 3){
	print "5\n";
}else{
	print "0\n";
}
