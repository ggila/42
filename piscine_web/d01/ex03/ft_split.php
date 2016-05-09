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
		while ($i < count($array))
		{
			$ret[$j] = $array[$i];
			$i++;
			$j++;
		}
		return ($ret);
	}
}

?>
