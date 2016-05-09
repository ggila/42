<?PHP

if (!$_GET)
	exit(0);

if (isset($_GET["action"]) && isset($_GET["name"]) && isset($_GET["value"]) && $_GET["action"] == "set")
	setcookie($_GET["name"],$_GET["value"]);
else if (isset($_GET["action"]) && isset($_GET["name"]) && $_GET["action"] == "get")
{
	$cook = $_COOKIE[$_GET["name"]];
	if($cook)
		echo($cook."\n");
}
else if (isset($_GET["action"]) && isset($_GET["name"]) && $_GET["action"] == "del")
	setcookie($_GET["name"], "");

?>
