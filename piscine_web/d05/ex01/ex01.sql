use db_ggilaber;
CREATE TABLE IF NOT EXISTS
ft_table
(
	id SMALLINT UNSIGNED
		NOT NULL
		AUTO_INCREMENT
		PRIMARY KEY,
	login VARCHAR(8)
		NOT NULL
		DEFAULT 'toto',
	groupe ENUM('staff', 'student', 'other')
		NOT NULL,
	date_de_creation date
		NOT NULL
)
DEFAULT CHARSET=UTF8;
