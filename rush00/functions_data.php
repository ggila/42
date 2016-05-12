<?php

// USERS

function user_save($users)
{
	$path = "private/db_user";

	$str = @serialize($users);
	$ret = @file_put_contents($path, $str, LOCK_EX);
	return (!($ret === FALSE));
}

function user_load()
{
	$path = "private/db_user";

	$str = @file_get_contents($path, $str);
	$str = @unserialize($str);
	return ($str);
}

// ARTICLES

function article_save($article)
{
	$path = "private/db_article";

	$array = article_load();
	$array[] = $article;
	$str = @serialize($array);
	$ret = @file_put_contents($path, $str, LOCK_EX);
	return (!($ret === FALSE));
}

function article_load()
{
	$path = "private/db_article";

	$str = @file_get_contents($path, $str);
	$str = @unserialize($str);
	return ($str);
}

function article_update($array_article)
{
	$path = "private/db_article";

	$str = @serialize($array_article);
	$ret = @file_put_contents($path, $str, LOCK_EX);
	return (!($ret === FALSE));
}

// ORDERS

function order_load()
{
	$path = "private/db_order";

	$str = @file_get_contents($path, $str);
	$str = @unserialize($str);
	return ($str);
}

function order_save($order)
{
	$path = "private/db_order";

	$str = @serialize($order);
	$ret = @file_put_contents($path, $str, LOCK_EX);
	return (!($ret === FALSE));
}

?>
