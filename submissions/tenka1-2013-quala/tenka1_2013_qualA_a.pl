$n=42;
while(1){
	$n *= 2;
	if($n > 130000000){
		print "$n\n";
		last;
	}
}
