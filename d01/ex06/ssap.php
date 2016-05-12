#!/usr/bin/php
<?PHP

function ft_split($str)
{
	$ret = array();
	$str = trim($str);
	if ($str[0])
	{
		$array = explode(" ", $str);
		sort($array);
		$i = 0;
		$j = 0;
		while (!$array[$i])
			$i++;
		if (!$array[$i])
			exit(0);
		while ($array[$i])
		{
			$ret[$j] = $array[$i];
			$i++;
			$j++;
		}
		return ($ret);
	}
}

$i = 0;
$prog_name = $argv[0];

if ($argc > 1)
{
	while ($i < $argc)
	{
		$str = $str." ".$argv[$i];
		$i++;
	}

	$array = ft_split($str);
	$i = 0;

	while ($array[$i])
	{
		if ($array[$i] != $prog_name)
			print($array[$i]."\n");
		$i++;
	}
}

?>
