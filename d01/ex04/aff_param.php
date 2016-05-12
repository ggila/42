#!/usr/bin/php
<?PHP

$i = 1;

if ($argc > 1)
{
	while ($argc - $i)
	{
		print($argv[$i]."\n");
		$i++;
	}
}

?>
