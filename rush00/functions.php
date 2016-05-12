<?php

if (!isset($_SESSION))
	session_start();
include 'functions_data.php';

/*
** New objects
*/

function get_new_id()
{
	$array = article_load();
	if (!$array)
		return 0;
	$max = -1;
	foreach($array as $article)
	{
		if ($article['id'] > $max)
			$max = $article['id'];
	}
	return ($max + 1);
}

function user_new($login, $passwd, $usertype)
{
	$usr = array('login' => $login,
				'passwd' => hash("whirlpool", $passwd),
				'usertype' => $usertype);
	return ($usr);
}

function article_new($title, $price, $genre, $format)
{
	$id = get_new_id();
	$article = array('id' => $id,
					'title' => $title,
					'price' => $price,
					'genre' => $genre,
					'format' => $format);
	return ($article);
}

/*
** Order functions
*/

function order_new($login, $cart)
{
	$article = array('login' => $login, 'cart' => $cart);
	return ($article);
}

function order_del($login, $timestamp)
{
	$orders = order_load();
	foreach ($orders as $key_order => $value_order)
	{
		if ($value_order['login'] === $login
			&& intval($value_order['timestamp']) === intval($timestamp))
			unset($orders[$key_order]);
	}
	order_save($orders);
}

/*
** Logging Functions
*/

function is_user_logged_on()
{
	if (isset($_SESSION['loggued_on_user']))
		return (TRUE);
	else
		return (FALSE);
}

function auth($login, $passwd)
{
	include 'functions_data.php';

	$path = "private/db_user";

	if (!file_exists($path))
		return (FALSE);
	$data = user_load();
	if (!isset($data, $login, $passwd))
		return (FALSE);
	foreach ($data as $key => $value)
	{
		if (isset($value["login"], $value["passwd"])
			&& ($value["login"] === $login) && ($value["passwd"] === hash("whirlpool", $passwd)))
			return (TRUE);
	}
	return (FALSE);
}

/*
** User Functions
*/

function user_is_admin($login)
{
	$user = user_get($login);
	if (isset($user, $user['usertype']))
	{
		if ($user['usertype'] === 'admin')
			return (TRUE);
	}
	return (FALSE);
}

function user_add($login, $passwd)
{
	$data = user_load();
	$data[] = user_new($login, $passwd, 'user');
	user_save($data);
}

function user_del($login)
{
	$data = user_load();
	foreach ($data as $key => $value)
	{
		if (isset($value['login']) && ($value['login'] === $login))
			unset($data[$key]);
	}
	user_save($data);
}

function user_get($login)
{
	$data = user_load();
	foreach ($data as $value)
	{
		if (isset($value["login"]) && ($value["login"] === $login))
			return ($value);
	}
	return (FALSE);
}

function passwd_set($login, $newpw)
{
	$data = user_load();
	foreach ($data as $key => $value)
	{
		if (isset($value["login"]) && ($value["login"] === $login))
		{
			$data[$key]["passwd"] = hash("whirlpool", $newpw);
			user_save($data);
			return (TRUE);
		}
	}
	return (FALSE);
}

/*
** article functions
*/

function is_valid_article($article)
{
	if (!$article['id'] || !is_numeric($article['id']) || $article['id'] < 1 || $article['id'] > 11)
		return FALSE;
	if (!$article["title"] || (strlen($article["title"]) == 0))
		return FALSE;
	if (!$article["price"] || !is_numeric($article["price"]) || ($article["price"] <= 0))
		return FALSE;
	if (!$article["genre"] || !$article["format"])
		return FALSE;
	if (count($article["genre"]) == 0 || count($article["format"]) == 0)
		return FALSE;
	return TRUE;
}

function add_article($title, $price, $genre, $format)
{
	$new = article_new($title, $price, $genre, $format);
	if (!is_valid_article($new))
		return;
	$array = article_load();
	foreach ($array as $key => $value)
	{
		if (($value['title'] == $new['title']) && ($value['format'] == $new['format']))
		{
			$array[$key] = $new;
			return (article_update($array));
		}
	}
	$array[] = $new;
	return (article_update($array));
}


function get_article($id)
{
	$array = article_load();
	foreach ($array as $key => $value)
	{
		if ($value['id'] === $id)
			return ($value);
	}
	return (FALSE);
}

function del_article($id)
{
	$array = article_load();
	foreach ($array as $key => $value)
	{
		if ($value['id'] == $id)
			unset($array[$key]);
	}
	return (article_update($array));
}

/*
** Cart functions
*/

function add_to_cart($id, $amount)
{
	if (!isset($_SESSION))
		session_start();
	if (!isset($_SESSION['cart']))
		$_SESSION['cart'] = array();

	$id = intval($id);
	$amount = intval($amount);
	foreach ($_SESSION['cart'] as $key => $value)
	{
		if ($value['id'] === $id)
		{
			$_SESSION['cart'][$key]['amount'] += $amount;
			return;
		}
	}
	$_SESSION['cart'][] = array('id' => $id, 'amount' => $amount);
}

/*
** Category function
*/

function get_cat_article($cat)
{
	$article = article_load();
	$ret = array();
	foreach ($article as $elem)
	{
		if ($cat == 'all')
			$ret[] = $elem;
		else
		{
			foreach ($elem['genre'] as $genre)
			{
				if ($genre == $cat)
					$ret[] = $elem;
			}
		}
	}
	return $ret;
}

function get_article_genre($article)
{
	$genre = array();
	if (isset($article['genre']))
	{
	foreach ($article['genre'] as $elem)
		$genre[] = $elem;
	}
	return $genre;
}

/*
** genre function
*/

function get_genre()
{
	$articles = article_load();
	$all_genre = array();
	foreach ($articles as $key_art => $value_art)
	{
		foreach ($value_art['genre'] as $key_genre => $value_genre)
		{
			if (array_search($value_genre, $all_genre) === FALSE)
				$all_genre[] = $value_genre;
		}
	}
	if (empty($all_genre))
		return ($all_genre);
	sort($all_genre);
	return $all_genre;
}

function del_category($cat_id)
{
	$articles = article_load();
	foreach ($articles as $key_art => $value_art)
	{
		foreach ($value_art['genre'] as $key_cat => $value_cat)
		{
			if ($value_cat == $cat_id)
				unset($articles[$key_art]['genre'][$key_cat]);
		}
	}
	article_update($articles);
}

?>
