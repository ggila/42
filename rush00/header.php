<?php
include 'functions.php';
?>

<header>
	<a href="index.php"><img class="logo" src="img/logo.png" title="Logo" alt="Logo"></div></a> 
	<a href="cart.php"><div class="btn btn_header">Cart</div></a>

<?php
if (is_user_logged_on()){
?>

	<a href="logout.php"><div class="btn btn_header btn_logout">Logout</div></a>
	<a href="settings.php"><div class="btn btn_header">Settings</div></a>

<?php
}else{
?>

	<a href="login.php"><div class="btn btn_header">Login</div></a>
	<a href="suscribe.php"><div class="btn btn_header">Suscribe</div></a>

<?php
}
?>

</header>
