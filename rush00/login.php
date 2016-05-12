<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Login</title>
	<link rel="stylesheet" type="text/css" href="css/style.css"/>
</head>

<body>

	<?php include('header.php'); ?>
	<?php include('navigation.php'); ?>

<section>
	
<?php
if (is_user_logged_on())
{
	header('Location: index.php');
	exit ;
}
if (isset($_POST['login'], $_POST['passwd'], $_POST['submit']) && $_POST['submit'] === "OK")
{
	if (auth($_POST['login'], $_POST['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_POST['login'];
		header("Location: index.php?valid=login");
	}
	else
		header("Location: login.php?error=login");
	exit;
}

?>

<h1>Connection</h1>

<?php
if (isset($_GET['error']) && $_GET['error'] === "login")
	echo '<p style="color:red;">Le couple login/mot de passe n\'est pas valide</p>';
?>

<p>Veuillez rentrer votre login et mot de passe:</p>
<form method="post" action="login.php">
Identifiant:	<input type="text" name="login" value="" /><br />
Mot de passe:	<input type="password" name="passwd" value="" />
				<input type="submit" name="submit" value="OK" />
</form>


</section>

</body>
</html>

