<?php
include 'functions.php';
if (is_user_logged_on())
{
	if (isset($_SESSION['cart']))
	{
		$orders = order_load();
		$orders[] = array('login' => $_SESSION['loggued_on_user'], 'cart' => $_SESSION['cart'], 'timestamp' => time());
		order_save($orders);
	}
	$_SESSION['cart'] = array();
	header('Location: index.php?valid=checkout');
	exit;
}
else
	header('Location: index.php');
?>
