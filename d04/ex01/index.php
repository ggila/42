<?PHP

session_start();

if (isset($_GET, $_SESSION, $_GET["login"], $G_GET["passwd"], $_GET["submit"]))
{
	if ($_GET["login"])
	{
		$_SESSION["login"] = $_GET['login'];
		$_SESSION['passwd'] = $_GET['passwd'];
	}
}

if (isset($_SESSION, $_SESSION['login'], $_SESSION['passwd']))
{
	$log = $_SESSION['login'];
	$pass = $_SESSION['passwd'];
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>ex01/index.php</title>
</head>
<body>
	<form action="">
		login:<br><input type="text" name="login"><br><br>
		passwd:<br><input type="text" name="passwd"><br><br>
		&emsp;<input name="submit" type="submit" value="OK">
	</form>
</body>
</html>
