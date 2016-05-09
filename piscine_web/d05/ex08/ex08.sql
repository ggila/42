SELECT nom, prenom, DATE_FORMAT(date_naissance, '%Y-%m-%d') AS date_format
	FROM fiche_personne
	WHERE DATE_FORMAT(date_naissance, '%Y') = DATE_FORMAT('1989-01-01', '%Y')
	ORDER BY nom
