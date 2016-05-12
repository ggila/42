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

if (isset($_SESSION['cart'], $_GET['action'], $_GET['id']) && $_GET['action'] === 'del')
{
	foreach ($_SESSION['cart'] as $key => $value)
	{
		if ($value['id'] === intval($_GET['id']))
			unset($_SESSION['cart'][$key]);
	}
}
?>

<h1>Mon Panier</h1>

<?php

if (!isset($_SESSION['cart']) || empty($_SESSION['cart']))
{
	echo 'Votre panier est vide :(<br /><br />';
	echo 'Choisissez vos article <a href="category.php?category=all">maintenant!</a>';
	exit ;
}
else
{
	if (is_user_logged_on())
		echo '<p><a href=checkout.php>Order now!</a><br/></p>';
	else
	{
		echo '<p>Please ';
		echo '<a href="login.php">login</a>';
		echo ' before ordering!<br/></p>';
	}
	$total = 0;
	echo '<table>';
	echo '<tr><td><b>Name</b></td>';
	echo '<td><b>Format</b></td>';
	echo '<td><b>Quantity</b></td>';
	echo '<td><b>Price</b></td>';
	echo '</tr><tr><td><br/></td></tr>';
	foreach ($_SESSION['cart'] as $key => $value)
	{
		$article = get_article($value['id']);
		$total += $value['amount'] * $article['price'];
		echo '<tr><td>';
		echo $article['title'].'</td><td>';
		echo $article['format'].'</td><td>';
		echo $value['amount'].'</td><td>';
		echo $article['price'].' €</td><td>';
		echo '[<a href="cart.php?action=del&id='.$article['id'].'">X</a>]</td>';
		echo '</tr>';
	}
	echo '<tr><td><br/></td></tr>';
	echo '<tr><td><b>Total:</b></td><td></td><td></td><td><b>'.$total.'€</b></td></tr>';
	echo '</table><br />';
}
?>

</section>

</body>
</html>
