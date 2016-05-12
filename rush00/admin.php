<?php

if (is_user_logged_on() && user_is_admin($_SESSION['loggued_on_user']))
{
if (isset($_GET['action'], $_GET['login'])
	&& $_GET['action'] == 'del_user')
	user_del($_GET['login']);

if (isset($_GET['action'], $_GET['login'], $_GET['timestamp'])
	&& $_GET['action'] == 'del_order')
	order_del($_GET['login'], $_GET['timestamp']);

if (isset($_GET['action'], $_GET['category'])
	&& $_GET['action'] == 'del_category')
{
	del_category($_GET['category']);
	header('Location: settings.php');
	exit;
}

if (isset($_GET['id'], $_GET['action']) && $_GET['action'] == 'del_article')
{
	del_article($_GET['id']);
	header('Location: settings.php');
}

?>


<h1>Orders</h1>
<?php
	$order = order_load();
	date_default_timezone_set('Europe/Paris');

	echo '<table>';
	echo '<tr><td><b>Login</b></td><td><b>Date</b></td><td><b>Action</b></td></tr>';
	foreach ($order as $key => $value)
	{
		echo '<tr><td>'.$value['login'].'</td>';
		echo '<td>'.date("d F Y H:i:s", $value['timestamp']).'</td>';
		echo '<td><a href="settings.php?action=del_order&login=';
		echo $value['login'];
		echo '&timestamp=';
		echo $value['timestamp'];
		echo '";">';
		echo 'Supprimer';
		echo '</a></td>';
		echo '</tr>';
	}
	echo '</table>'
?>

<h1>Admin</h1>



<h1 style="font-size:large;">Articles</h1>
<?php
	$article = article_load();
	echo '<table>';
	echo '<tr><td><b>Name</b></td>';
	echo '<td><b>Format</b></td>';
	echo '<td><b>genre</b></td>';
	echo '<td><b>Price (€)</b></td>';
	echo '<td><b></b></td>';
	echo '<td><b>delete</b></td>';
	echo '</tr><tr><td><br/></td></tr>';
	foreach ($article as $elem)
	{
		$genre = get_article_genre($elem);
		$price = $elem['price'];
		$id = $elem['id'];
		echo '<tr><td>';
		echo $elem['title'].'</td><td>';
		echo $elem['format'].'</td><td><ul>';
		foreach ($genre as $elem)
			echo '<li>'.$elem.'</li>';
		echo '</ul></td><td>';
		echo $price.'</td><td>';
		echo '</td><td>';
		echo '[<a href="settings.php?action=del_article&id='.$id.'">X</a>]</td>';
		echo '</tr>';
	}
	echo '</table><br />';
?>








<h1 style="font-size:large;">Genres</h1>

<?php
	$category = get_genre();
	echo '<table>';
	echo '<tr><td><b>Nom</b></td><td><b>Action</b></td></tr>';
	foreach ($category as $key => $value)
	{
		echo '<tr><td>'.$value.'</td>';
		echo '<td><a href="settings.php?action=del_category&category=';
		echo $value;
		echo '">';
		echo 'Supprimer';
		echo '</a></td></tr>';
	}
	echo '</table>'
?>


<h1 style="font-size:large;">Users</h1>
<?php
	$user = user_load();

	echo '<table>';
	echo '<tr><td><b>Nom</b></td><td><b>Role</b></td><td><b>Action</b></td></tr>';
	foreach ($user as $key => $value)
	{
		echo '<tr><td>'.$value['login'].'</td>';
		echo '<td>'.$value['usertype'].'</td>';
		if (!user_is_admin($value['login']))
		{
			echo '<td><a href="settings.php?action=del_user&login=';
			echo $value['login'];
			echo '">';
			echo 'Supprimer';
			echo '</a></td>';
			echo '</tr>';
		}
	}
	echo '</table>';
?>

<?php } ?>
