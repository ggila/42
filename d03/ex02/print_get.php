<?PHP

if (!$_GET)
	exit(0);

foreach ($_GET as $key => $value)
	echo($key." : ".$value."\n");

?>
