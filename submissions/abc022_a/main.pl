($_, $min, $max) = split / /, <>;
$current=<>;
$ans=0;
$ans++ if($min <= $current && $current <= $max);
while(<>){
	$current += $_;
	$ans++ if($min <= $current && $current <= $max);
}
print "$ans\n";
