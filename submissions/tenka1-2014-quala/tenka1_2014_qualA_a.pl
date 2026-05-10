@n;
for $i(1..1000){
	push @n, $i;
}
@n = sort {$a cmp $b} @n;
for $n(@n){
	print "$n\n";
}
