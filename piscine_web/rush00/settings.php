<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>My minishop</title>
	<link rel="stylesheet" type="text/css" href="css/style.css"/>
</head>

<body>

	<?php include('header.php'); ?>
	<?php include('navigation.php'); ?>

<section>

<?php
if (!is_user_logged_on())
{
	header('Location: index.php');
	exit ;
}

if (isset($_POST["oldpw"], $_POST["newpw"], $_POST["submit"]))
{
	if (auth($_SESSION['loggued_on_user'], $_POST['oldpw'])
		&& ($_POST["submit"] === "OK") && ($_POST["oldpw"] !== "") && ($_POST["newpw"] !== ""))
	{
		passwd_set($_SESSION['loggued_on_user'], $_POST["newpw"]);
		header('Location: settings.php?valid=newpw');
		exit ;
	}
	else
	{
		header('Location: settings.php?invalid=error');
		exit;
	}
}


?>
	<h1>My settings</h1>
	<h1 style="font-size:large">Modifier le mot de passe</h1>

<?php
	if(isset($_GET['invalid']) && $_GET['invalid'] == 'error')
		echo '<p style="color:red;">Le couple login/mot de passe n\'est pas valide</p>';
	if(isset($_GET['valid']) && $_GET['valid'] == 'newpw')
		echo '<p style="color:green;">Le mot de passe a été modifié</p>';
?>

<form method="post" action="settings.php">
Ancien mot de passe:	<input type="password" name="oldpw" value="" /><br />
Nouveau mot de passe:	<input type="password" name="newpw" value="" />
<input type="submit" name="submit" value="OK" />

	<?php include('admin.php'); ?>

</section>

</body>
</html>
