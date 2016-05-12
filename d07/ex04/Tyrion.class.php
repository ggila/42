<?PHP

class Tyrion extends Lannister
{
	public function getSize(){
		return 'Short';}

	public function SleepWith($sexmate)
	{
		if (get_class($sexmate) === 'Jaime')
			printf('Not even if I\'m drunk'.PHP_EOL);
		else if (get_class($sexmate) === 'Cersei')
			printf('Not even if I\'m drunk'.PHP_EOL);
		else if (get_class($sexmate) === 'Sansa')
			printf('Let\'s do this'.PHP_EOL);
	}
/*	public function __construct() {
		parent::__construct();
		print('My name is Tyrion'.PHP_EOL);
	}
*/}

?>
