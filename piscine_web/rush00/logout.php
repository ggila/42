<?php
include 'functions.php';
if (is_user_logged_on())
	unset($_SESSION['loggued_on_user']);
header("location: index.php");
exit ;
?>
