#!/usr/bin/php
<?PHP

while (1)
{
	$flag_nan = 0;
	$flag_sign = 0;
	$flag_empty = 0;
	print("Entrez un nombre: ");
	$var = trim(fgets(STDOUT));
	$var[strlen($var)] = "\n";
	if ($var == false)
	{
		print("\n");
		exit(0);
	}
	if ($var[0] == "\n")
		$flag_empty = 1;
	if (strlen($var) > 10)
		print("overflow\n");
	else
	{
		$good_var = 0;
		$coef = 1;
		$sign = 0;

		if (($var[0] == "+" || $var[0] == "-") && $var[1] != "\n")
		{
			$flag_sign = $var[0];
			$var[0] = 0;
		}

		$end = $flag_sign == "0" ? 0 : 1;
		for ($i = strlen($var) - 2; $i >= end; $i--)
		{
			if (!is_numeric($var[$i]))
				$flag_nan = 1;
			else
			{
				$good_var = $good_var + $var[$i] * $coef;
				$coef *= 10;
			}
		}

		if ($flag_nan || $flag_empty)
		{
			print("'");
			if ($flag_sign != "0")
				print($flag_sign);
			for ($i = $flag_sign ? 1 : 0; $i < strlen($var) - 1; $i++)
				print("$var[$i]");
			print("' n'est pas un chiffre\n");
		}
		else
		{
			print("Le chiffre ");
			if ($flag_sign != "0")
				print($flag_sign);
			print("$good_var est ");
			if ($var % 2)
				print("Impair\n");
			else
				print("Pair\n");
		}
	}
}

?>
