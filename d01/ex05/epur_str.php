#!/usr/bin/php
<?PHP

function is_two_space($str)
{
	$i = 1;
	while ($i < strlen($str))
	{
		if ($str[$i] == " " && $str[$i - 1] == " ")
			return 1;
		$i++;
	}
	return 0;
}

if ($argc == 2)
{
	$i = 1;
	$str = trim($argv[1]);
	while (is_two_space($str))
		$str = str_replace("  ", " ", $str);
	print($str."\n");
}

?>
