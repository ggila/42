#!/usr/bin/php
<?PHP

function ft_is_sort($array)
{
	for ($i = 1; $i < count($array); $i++)
		if (strcmp($array[$i], $array[$i - 1]) < 0)
			return false;
	return true;
}

?>
