<nav>

<?php
$category = array();
?>

<a href="category.php?category=all"><div class="btn btn_nav">All</div></a>

<?php

$category = get_genre();
foreach ($category as $key => $value)
{
	echo '<a href="category.php?category=';
	echo $value;
	echo '"><div class="btn btn_nav">';
	echo $value;
	echo '</div></a>';
}

?>

</nav>
