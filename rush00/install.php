<?php

include 'functions.php';

$path = "private";
if (!file_exists($path))
	mkdir($path);

$users = array(user_new('root', 'root', 'admin'));
user_save($users);

article_save(article_new('Usual Suspects', '15.99', array('Suspence', 'Test1', 'Test2'), 'DVD'));
article_save(article_new('Usual Suspects', '15.99', array('Suspence', 'Test1', 'Test2'), 'Bluray'));
article_save(article_new('Usual Suspects', '15.99', array('Suspence', 'Test1', 'Test2'), 'VHS'));
article_save(article_new('Minority Report', '15.99', array('Suspence', 'Sci-fi'), 'DVD'));
article_save(article_new('Minority Report', '15.99', array('Suspence', 'Sci-fi'), 'Bluray'));
article_save(article_new('Minority Report', '15.99', array('Suspence', 'Sci-fi'), 'VHS'));
article_save(article_new('Django Unchained', '15.99', array('Suspence'), 'DVD'));
article_save(article_new('Django Unchained', '15.99', array('Suspence'), 'Bluray'));
article_save(article_new('Django Unchained', '15.99', array('Suspence'), 'VHS'));
article_save(article_new('Ocean Eleven', '15.99', array('Suspence', 'Comedy'), 'DVD'));
article_save(article_new('Ocean Eleven', '15.99', array('Suspence', 'Comedy'), 'Bluray'));

$orders = array();
order_save($orders);

?>
