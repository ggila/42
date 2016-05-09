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

<h1>Categories</h1>

<?php

if(isset($_POST['amount'], $_POST['id'], $_POST['submit'])
	&& $_POST['amount'] > 0 && $_POST['submit'] == 'Add to cart')
{
	add_to_cart( $_POST['id'],  $_POST['amount']);
	echo '<p style="color:green;">Votre article a été ajouté!</p>';
}

$data = get_cat_article($_GET['category']);
echo '<ul>';
foreach ($data as $key => $value)
{
	echo '<li><form action="category.php?category='.$_GET['category'].'" method="post">';
	echo $value['id']."   ".$value['title']."   ".$value['format']."             ".$value['price'];
	echo '<input type="number" value=1 name="amount">';
	echo '<input type="hidden" value='.$value['id'].' name="id">';
	echo '<input type="submit" name="submit" value="Add to cart">';
	echo '</form></li>';
}
echo '</ul>';


?>

</section>

</body>
</html>


