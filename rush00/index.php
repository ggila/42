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
<h1>Bienvenue</h1>

<?php

if (isset($_GET['valid']) && $_GET['valid'] === 'checkout')
	echo '<p style="color:green;">Votre commande a été validée</p>';
if (isset($_GET['valid']) && $_GET['valid'] === 'suscribe')
	echo '<p style="color:green;">Votre compte a été crée</p>';
if (isset($_GET['valid']) && $_GET['valid'] === 'login')
	echo '<p style="color:green;">Vous êtes maintenant connecté</p>';



if (is_user_logged_on())
	echo 'Bienvenue '.$_SESSION['loggued_on_user'].'!';
else
	echo 'Vous n\'êtes pas connecté';



?>
</section>

</body>
</html>
