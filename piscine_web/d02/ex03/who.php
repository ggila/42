#!/usr/bin/php
<?PHP

if (!is_file("/var/run/utmpx"))
	exit(0);

$str = file_get_contents("/var/run/utmpx");
$user = get_current_user();
$key = "a256user/a4id/a32line/ipid/itype/I2time/a256host/i16padi";
$i = 1256;
$j = 0;

date_default_timezone_set("Europe/Paris");

$str = substr($str, 1256);

while (strlen($str) > 0)
{
	$temp = unpack($key, $str);
	if (!strncmp($temp["user"], $user, strlen($user)) && $temp["type"] == 7)
	{
		$date = date("M  j H:i ", $temp["time1"]);
		$ret[$j] .= "$user"." ".substr($temp["line"], 0, 7)."  ".$date."\n";
		$j++;
	}
	$str = substr($str, 628);
}

sort($ret);
foreach ($ret as $elem)
	print($elem);
?>
