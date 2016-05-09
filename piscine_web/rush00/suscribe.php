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
	header("Location: index.php");
	exit ;
}
if (isset($_POST["login"],  $_POST["passwd"], $_POST["submit"]) && ($_POST["submit"] === "OK"))
{		
	if (($_POST["login"] === "") || ($_POST["login"] === "") || !user_get($_POST["login"]) === FALSE)
		header("Location: suscribe.php?error=suscribe");
	else
	{
		user_add($_POST["login"], $_POST["passwd"]);
		header("Location: index.php?valid=suscribe");		
	}
	exit ;
}

?>

	<h1>Creez votre compte</h1>
	<?php
	if (isset($_GET['error']) && $_GET['error'] === "suscribe")
		echo '<p style="color:red;">Le login n\'est pas valide</p>';
	?>
	<p>Veuillez entrez un login et un mot de passe:</p>
	<form method="post" action="suscribe.php">
	Identifiant:	<input type="text" name="login" value="" /><br />
	Mot de passe:	<input type="password" name="passwd" value="" />
					<input type="submit" name="submit" value="OK" />
	</form>
</sections>

</body>
</html>

